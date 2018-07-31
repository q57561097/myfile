<template>
  <div>
    <Header></Header>
    <div class="demo">
      <form v-for="(i, index) in list">
            <div v-bind:style="{width:content_width}">
            <label><input type="checkbox" v-model="permission_list" v-bind:value="i.id">{{ i.name }}</label>
            <b v-on:click="openShutManager(i.id), getFactory(i.id)">→</b>
            <div v-bind:id="i.id" style="display: none;  margin-left: 15px">
            <form  v-for="(site, siteKey) in factory_info[i.id]">
              <label><input type="checkbox" v-model="permission_list" v-bind:value="site.id">{{site.name}}</label>
              <b v-on:click="openShutManager(i.id+siteKey)">→</b>
              <div v-bind:id="i.id+siteKey" style="display: none;  margin-left: 15px">
                <form  v-for="(shop, shopKey) in site.members">
                  <label><input type="checkbox" v-model="permission_list" v-bind:value="shop.id">{{shop.name}}</label>
                  <b v-on:click="openShutManager(i.id + siteKey + shopKey)">→</b>
                  <div v-bind:id="i.id+siteKey + shopKey" style="display: none;  margin-left: 15px">
                    <form  v-for="(group, groupKey) in shop.members">
                      <label><input type="checkbox" v-model="permission_list" v-bind:value="group.id">{{group.name}}</label>
                      <b v-on:click="openShutManager(i.id + siteKey + shopKey + groupKey)">→</b>
                      <div v-bind:id="i.id+siteKey + shopKey + groupKey" style="display: none;  margin-left: 15px">
                        <form  v-for="(machine, machineKey) in group.members">
                          <label><input type="checkbox" v-model="permission_list" v-bind:value="machine.machine_id">{{machine.name}}</label>
                        </form>
                      </div>
                    </form>
                  </div>
                </form>
              </div>
            </form>
            </div>
            </div>
      </form>
    </div>
    <div>
      <form class="form">
        <select v-model="table" class="button">
          <option value="">moses</option>
          <option value="jesus">jesus</option>
        </select>
        <select v-model="server" class="button">
          <option  value="9201">生产服</option>
          <option  value="9200">测试服</option>
        </select>
        <select class="button" v-model="client">
          <option v-for="(num, port) in clients" v-bind:value="port">{{port}}'|'{{num}}</option>
        </select>
        <input type="button" value="加工" v-on:click="handleSimulator('', 'start')" class="button">
        <input type="button" value="急停" v-on:click="handleSimulator('', 'estop')" class="button">
        <input type="button" value="自动变化" v-on:click="handleSimulator('start_change_status', '')" class="button">
        <input type="button" value="启动" v-on:click="handleSimulator('start_simulator', '')">
        <input type="number" id="client_port"  placeholder="请输入端口号" class="number">
        <input type="button" value="启动服务器" v-on:click="startSimulator('start_new_client')">
        <input type="button" value="关闭服务器" v-on:click="startSimulator('stop_client')">
        <input type="number" id="min_num" placeholder="请输入最小值" class="number">毫秒
        <input type="number" id="max_num" placeholder="请输入最大值" class="number">毫秒
        <input type="button" value="设置每循环时间" v-on:click="alterTime('alter_working_change')">
        <input type="button" value="设置轴变化时间" v-on:click="alterTime('alter_info_change')">
        <input type="button" value="设置自动变化时间" v-on:click="alterTime('set_status_change_time')">
        <input type="text" id="error_type" placeholder="报警类型">
        <input type="text" id="error_num" placeholder="报警编号">
        <input type="text" id="error_info" placeholder="报警内容">
        <input type="button" value="发送报警" v-on:click="sendError()">
      </form>
    </div>
    <Footer></Footer>
  </div>
</template>
<script>
  import Vue from 'vue'
  export default {
    data () {
      return {
        list: [],
        factory_info: {},
        permission_list: [],
        content_width:screen.width/8 + 'px',
        server: '9200',
        table: '',
        clients: {},
        client: ''
      }
    },
    created () {
      this.getData();
      this.showClient()
    },
    methods: {
      getData () {
        let v = this;
        v.$api.post('', {'func': 'list_factory', 'data': {'search': ''}},
          function (r) {
            v.list = r.data
          })
      },
      openShutManager(oTargetObj){
      let targetObj =  typeof oTargetObj === "string" ? document.getElementById(oTargetObj) : oTargetObj;
      if(targetObj.style.display!=="none"){
        targetObj.style.display="none";
      } else {
        targetObj.style.display="block";
      }
    },
      getFactory(factory_id){
        let v = this;
        if (v.factory_info[factory_id]) return;
        v.$api.post('', {'func': 'get_factory_info', 'data': {'factory_id': factory_id}},
        function (r) {
          Vue.set(v.factory_info,factory_id,  r.members);
          console.log(v.factory_info)
        })
      },
　　　　handleSimulator(func ,order){
        let v = this;
        if (!func){
          func = 'handle_simulator'
        }
        if (!order){
          order = ''
        }
        let data = {'func': func, 'port': v.server, 'data': {'permission': v.permission_list,
          'order': order , 'client_port': parseInt(v.client), 'table': v.table}};
        v.$api.post('', {'func': 'send_data',  'data': data},
          function (r) {
            console.log(v.factory_info)
          })
        },
       showClient(){
        let v = this;
         let new_client = {};
        let client;
        this.$api.post('', {'func': 'send_data', 'data':{'func': 'show_client', 'port': v.server}},
        function (r) {
            let data = r.data;
            // v.clients = {};
            for (client in data){
              // Vue.set(v.clients ,client, data[client]['box'].length);
              new_client[client] = data[client]['box'].length;
            }
          Vue.set(v, 'clients', new_client)
          });
       },
      startSimulator(func){
        let v = this;
        let client_port = document.getElementById("client_port").value;
        let data = {'func': func, 'port': v.server, 'data': {'port': parseInt(client_port)}};
        v.$api.post('', {'func': 'send_data',  'data': data},
          function (r) {
            v.showClient()
          })
      },
      alterTime(func){
        let v = this;
        let min_num = document.getElementById("min_num").value;
        let max_num = document.getElementById("max_num").value;
        let change_time = [parseInt(min_num), parseInt(max_num)];
        let data = {'func': func, 'port': v.server, 'data': {'change_time': change_time,
            'working_time': change_time, 'info_change_time': parseInt(max_num), 'permission': v.permission_list,
            'table': v.table}};
        v.$api.post('', {'func': 'send_data',  'data': data})
      },
　　　 sendError(){
        let v = this;
        let error_type = document.getElementById("error_type").value;
        let error_num = document.getElementById("error_num").value;
        let error_info = document.getElementById("error_info").value;
        let send_data = {'permission': v.permission_list, 'table': v.table};
        if (error_num){
          send_data['error_num'] = error_num
        }
        if (error_type){
          send_data['error_type'] = error_type
        }
        if (error_info){
          send_data['error_info'] = error_info
        }
        let data = {'func': 'set_error', 'port': v.server, 'data': send_data};
        v.$api.post('', {'func': 'send_data',  'data': data})}
    },
    watch:{
      server : function (val) {
        this.showClient()

      }

    }
  }
</script>
<style>
  .demo{
    display: flex;                /*设置为flex布局*/
    justify-content: space-between;
    height: 800px;
    flex-wrap: wrap;
    overflow: auto;
  }
  .button{
    height: 25px;
  }
  .form{
    display: flex;                /*设置为flex布局*/
    flex-wrap: wrap;
    justify-content: center;
  }
  .number{
    width: 80px;
  }
</style>
