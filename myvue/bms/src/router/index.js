import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/pages/Home'
import FactoryList from '@/pages/FactoryList'
import Mouse from '@/pages/mouse'
import TuBiao from '@/pages/tubiao'
import MachineList from '@/pages/MachineList'


Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      component: Home
    },
    {
      path: '/factoryList',
      component: FactoryList
    },
    {
      path: '/mouse',
      component: Mouse
    },
    {
      path: '/tu',
      component: TuBiao
    },
    {
      path: "/machine",
      component: MachineList
    }
  ]
})
