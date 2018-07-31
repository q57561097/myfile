import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import Index from '@/pages/Index'
import Content from '@/pages/Content'
import Factory from '@/pages/simulator/list_factory'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/name',
      name: 'name',
      component: Index
    },
    {
      path: '/Content/:id',
      component: Content
    },
    {
      path: '/factory',
      name: 'factory',
      component: Factory
    }
  ]
})
