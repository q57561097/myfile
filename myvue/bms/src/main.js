// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import 'bootstrap/dist/css/bootstrap.min.css'
import 'bootstrap/dist/css/bootstrap.css'
import store from './store'
import VueI18n from 'vue-i18n'
Vue.config.productionTip = false;
Vue.use(VueI18n);
/* eslint-disable no-new */
const i18n = new VueI18n({
  locale: 'zh', // 语言标识
  messages: require('./common/lang/lang')
});
const DI18n = require('di18n-translate')
const di18n = new DI18n({
  locale: "zh",       // 语言环境
  isReplace: false,   // 是否进行替换(适用于没有使用任何构建工具开发流程)
  messages: require('./common/lang/lang2')
});
function trans_language(text) {
 return di18n.$t(text)
}


new Vue({
  el: '#app',
  router,
  i18n,
  store: store,
  components: { App },
  template: '<App/>'
});
Vue.prototype.di18n = trans_language;


