<template>
  <div>
    <Header></Header>
    <div class="article_list">
      <ul>
        <li v-for="(i, index) in list">
            <router-link :to="'/content/' + i.id">
              {{ i.name}}
            </router-link>
        </li>
      </ul>
    </div>
    <Footer></Footer>
  </div>
</template>
<script>
  export default {
    data () {
      return {
        list: []
      }
    },
    created () {
      this.getData()
    },
    methods: {
      getData () {
        var v = this
        v.$api.post('', {'func': 'list_factory', 'data': {'search': ''}},
          function (r) {
            v.list = r.data
          })
      }
    }
  }
</script>
