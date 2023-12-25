<!-- app.vue -->

<template>
  <div id="app">
    <!-- 顶部区域 -->
    <Header />

    <!-- 中间区域，左侧导航栏和右侧显示画面 -->
    <div class="main-container">
      <!-- 左侧导航栏 -->
      <Navigation />

      <!-- 右侧显示画面 -->
      <router-view></router-view>
    </div>
  </div>
</template>

<script>
import Header from '@/components/Header.vue';
import Navigation from '@/components/Navigation.vue';

export default {
  components: {
    Header,
    Navigation,
  },
};
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;

   /* 添加height: 100vh; 使用视口的高度作为高度值 */
   height: 100vh;
   margin: 0; /* 移除默认的margin，确保 #app 没有外边距 */
   overflow: hidden; /* 防止子元素溢出视口 */
}
.main-container {
  display: grid;
  grid-template-columns: 1fr 9fr; /* 例子：左右两栏 */
  background-color: #ffffff; /* 右侧显示画面的背景色，可以根据需要调整 */
  height: 100%;
}

/* 可根据需要添加其他样式 */
</style>
