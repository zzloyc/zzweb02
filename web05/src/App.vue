<template>
  <div id="app">
    <Header />
    <div class="main-container">
      <Navigation :changePage="changePage" />
      <router-view />
    </div>
  </div>
</template>

<script>
import Header from '@/components/Header.vue'
import Navigation from '@/components/Navigation.vue'

export default {
  components: {
    Header,
    Navigation
  },
  methods: {
    changePage( page) {
      this.$router.push(page)
    },
  }
}
</script>

<style>
#app {
  text-align: center;
  display: flex;
  flex-direction: column;
  min-height: 100vh;
}

.main-container {
  display: flex;
  flex: 1;
  
}

.content {
  flex: 1;
}

/* 其他样式保持不变 */
</style>