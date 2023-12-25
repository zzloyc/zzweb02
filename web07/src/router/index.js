// index.js
import Vue from 'vue';
import VueRouter from 'vue-router';
import SystemSettings from '@/components/SystemSettings.vue';
import PersonalSettings from '@/components/PersonalSettings.vue';
import NetworkSettings from '@/components/NetworkSettings.vue';
import ExperimentSettings from '@/components/ExperimentSettings.vue';
import NameSettings from '@/components/NameSettings.vue';
import AddressSettings from '@/components/AddressSettings.vue';

Vue.use(VueRouter);

// 路由配置示例
const routes = [
  { path: '/system-settings', name: 'SystemSettings', component: SystemSettings, children: [
    { path: 'network', component: NetworkSettings },
    { path: 'experiment', component: ExperimentSettings },


  ]},
  { path: '/personal-settings', name: 'PersonalSettings', component: PersonalSettings , children: [
    { path: 'name', component: NameSettings },
    { path: 'address', component: AddressSettings },
  ]


},
{ path: '/', redirect: '/system-settings/network' },
//  { path: '/name', component: NameSettings },
//  { path: '/address', component: AddressSettings },
];

const router = new VueRouter({
  routes,
});

export default router;
