// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import '@/styles/global.css'; // 引入全局样式文件
Vue.config.productionTip = false
// 引入 axios
import axios from 'axios';

//Vue.use(VueAxios,axios)
// 挂载一个自定义属性$http
Vue.prototype.http = axios;
// 全局配置axios请求根路径(axios.默认配置.请求根路径)
//axios.defaults.baseURL = 'http://yufei.shop:3000'


/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
