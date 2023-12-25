import Vue from 'vue'
import App from '../App.vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import NetworkSettings from '../components/NetworkSettings.vue'
import ExperimentSettings from '../components/ExperimentSettings.vue'

Vue.config.productionTip = false

Vue.use(VueRouter)

const routes = [
  { path: '/', component: Home },
  { path: '/network', component: NetworkSettings, name: 'Network Settings' },
  { path: '/experiment', component: ExperimentSettings, name: 'Experiment Settings' }
  // Add more routes as needed
]

const router = new VueRouter({
  mode: 'hash',
  routes
})
export default router;
new Vue({
  render: (h) => h(App),
  router
}).$mount('#app')

