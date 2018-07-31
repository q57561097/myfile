import Vue from 'vue'
import Vuex from 'vuex'


const state = {
  index : 0
};

const mutations = {
  change_index(state, index){
    state.index = index
  }
};

Vue.use(Vuex)
export default new Vuex.Store({
  state,
  mutations
})
