<template>
    <div class="navl">
      <div class="leftNav">
      <img class="logo" src="../../static/img/logo.png"/>
      <span class="content1">{{$t("message.hello")}}</span>
      </div>
      <div class="navList navFontSize">
        <div class="navEl" :class="{active : index === 0}"  @click="set_index(0)">
          <router-link to="/factoryList">
            <div class="navText">
              工厂列表
            </div>
          </router-link>
        </div>
        <div class="navEl" :class="{active : index === 1}">
          <router-link to="/">
            <div class="navText" @click="set_index(1)">
              机床配置信息
            </div>
          </router-link>
        </div>
        <div class="navEl" :class="{active : index === 2}">
          <router-link to="/">
            <div class="navText" @click="set_index(2)">
              369
            </div>
          </router-link>
        </div>
        <div class="navEl" :class="{active : index === 3}" @click="set_index(3)">
          <router-link to="/">
            <div class="navText" @click="set_index(3)">
              {{6 + "个"}}
            </div>
          </router-link>
        </div>
        <div class="navEl" :class="{active : index === 4}" @click="set_index(4)">
          <router-link to="/">
            <div class="navText" @click="set_index(4)">
            </div>
          </router-link>
        </div>
      </div>
    </div>
</template>

<script>
	export default {
		name: "nva",
    data () {
		  return {
		    index: this.$store.state.index,
      }
    },
    methods: {
		  set_index: function (index) {
		    this.$store.commit('change_index', index);
        this.index = index;}
    }
	}
</script>

<style scoped>
  .navl
  {
    background-color: rgba(21, 135, 175, 1);
    width: 100%;
    height: 5%;
    position: fixed;
    top: 0;
    color: #ffffff;
  }
  .leftNav
  {
    display:flex;
    align-items:center;
    width: 100%;
    height: 100%;
    margin-left: 1%;
  }
  .logo
  {
    height: 80%;
    float: left;
  }
  .content1
  {

    float: left;
    margin-left: 0.5%;
  }
  .navList
  {
    width: 6%;
    background-color: rgba(0, 93, 139, 1);
    position: fixed;
    top: 5%;
    height: 95%;
    /*display: flex;*/
    /*flex-direction: column;*/
  }
  .navEl
  {
    height: 8%;
  }
  .navText
  {
    color: #ffffff;
    position: absolute;
    left: 10%;
    margin-top: 25%;

  }
  .active
  {
    background-color: rgba(182, 155, 90, 1);
  }
  .navFontSize{
    font-size: 16px;
  }
</style>
