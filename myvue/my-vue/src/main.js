// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'

// 引用API文件
import api1 from './api/index.js'
import utils from './utils/index.js'
// 将API方法绑定到全局
Vue.prototype.$api = api1
Vue.prototype.$utils = utils
Vue.config.productionTip = false
localStorage.setItem('sessionId', '50e12e7a444111e8a0e000163e026f57')

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  template: '<App/>',
  components: { App }
})
