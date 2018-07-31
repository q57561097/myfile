<template>
  <div id="main"></div>
</template>

<script>
  var echarts = require('echarts/lib/echarts');
  // 引入柱状图
  require('echarts/lib/chart/bar');
  // 引入提示框和标题组件
  require('echarts/lib/component/tooltip');
  require('echarts/lib/component/title');
  require('echarts/lib/chart/pie')
	export default {
		name: "tubiao",
    methods: {
		  set_tu(){
        var myChart = echarts.init(document.getElementById('main'), "dark");
// 绘制图表
        myChart.setOption({
          series : [
            {
              name: '访问来源',
              type: 'pie',
              radius: '55%',
              roseType:'angle',
              data:[
                {value:235, name:'视频广告', textStyle:{color: 'rgba(255, 255, 255, 255)'}},
                {value:274, name:'联盟广告'},
                {value:310, name:'邮件营销'},
                {value:335, name:'直接访问'},
                {value:400, name:'搜索引擎'}
              ]
            }
          ]
        })
      },
    },
    mounted: [function () {this.set_tu()

    }]
	}
</script>

<style scoped>
  #main{
    width: 800px;
    height: 400px;
  }
</style>
