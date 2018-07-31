<template>
  <div>
    <nva></nva>
    <div class="body">
      <div class="nav2 navFontSize mainBody">
        <router-link to="/" class="navFont">首页</router-link>
        <img src="../../static/img/nav.png" class="navMove navImg"/>
        <span class="navMove navFontColor">工厂列表</span>
      </div>
      <nvaLine></nvaLine>
      <div class="searchBody mainBody">
          <input type="text" class="search" placeholder="工厂名字/工厂ID/车间/生产线/盒子ID"/>
          <div class="buttonBody">
            <div>
              <input type="button" value="创建工厂" class="searchButton"/>
            </div>
            <div>
              <input type="button" value="导入Excel快速创建" class="searchButton"/>
            </div>
            <div>
              <input type="button" value="下载Excel模板" class="searchButton"/>
            </div>
          </div>
      </div>
      <div class="mainBody row">
        <table border="1" class="col-md-12 col-sm-12 col-xs-12">
          <tr>
            <td class="col-md-3 col-sm-3 col-xs-3 row1" height="30px">工厂ID</td>
            <td class="col-md-5 col-sm-5 col-xs-5 row1" height="30px">工厂名称</td>
            <td class="col-md-2 col-sm-2 col-xs-2 row1" height="30px">操作</td>
            <td class="col-md-2 col-sm-2 col-xs-2 row1" height="30px">操作</td>
          </tr>
        </table>
      </div>
    </div>
  </div>
</template>

<script>
  import nva from '../components/nva'
  import nvaLine from '../components/navLine'
	export default {
		name: "FactoryList",
    components:{
		  nva: nva,
      nvaLine: nvaLine
    }
	}
</script>
<style scoped>
  .nav2
  {
    display: flex;
    /*position: relative;*/
    /*left: 8%;*/
    height: 4%;
  }
  .navFont
  {
    color: #000000;
    text-decoration: underline;
  }
  .navMove
  {
    margin-left: 1%;
  }
  .navFontSize{
    font-size: 16px;
  }
  .navFontColor
  {
    color: #B69B5A;
  }
  .search
  {
    height: 70%;
    width: 297px;
    background:  url("../../static/img/serach.png") no-repeat 10px  center;
    background-size: auto 80%;
    border-radius: 5px;
    border-width: 1px;
    text-align: center;


  }
  .body
  {
    position: fixed;
    left: 6%;
    height: 100%;
    width: 94%;
  }
  .mainBody
  {
    margin-left: 1%;
    width: 98%;
  }
  .navImg
  {
    height: 50%;
  }
  .searchBody
  {
    height: 6%;
    display: flex;
    justify-content: space-between;
    align-items: center;

  }
  .buttonBody
  {
    display: flex;
    justify-content: right;

  }
  .searchButton
  {
    background: rgba(57, 150, 182, 1);
    border-radius: 5px;
    color: #ffffff;
    width: 130px;
    height: 32px;
    box-shadow: none;
    border: none;
    margin-left: 10px;
  }
  .row1
  {
    background: rgba(57, 150, 182, 1);
    color: #ffffff;
    border-color: #000000;
  }



</style>
