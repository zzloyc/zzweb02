<!-- Navigation.vue -->
<template>
  <div class="navigation">
    <router-link
      v-if="isSystemSettings"
      to="/system-settings/network"
      class="nav-link"
      active-class="active-link"
    >
      网络设置
    </router-link>
    <router-link
      v-if="isSystemSettings"
      to="/system-settings/experiment"
      class="nav-link"
      active-class="active-link"
    >
      实验设置
    </router-link>
    <router-link
      v-if="!isSystemSettings"
      to="/personal-settings/name"
      class="nav-link"
      active-class="active-link"
    >
      名字设置
    </router-link>
    <router-link
      v-if="!isSystemSettings"
      to="/personal-settings/address"
      class="nav-link"
      active-class="active-link"
    >
      地址设置
    </router-link>
  </div>
</template>


<script>
export default {
  computed: {
    isSystemSettings() {
      return this.$route.matched.some(route => route.name === 'SystemSettings');
    },
  },
};
</script>

<style scoped>
/* 样式 */
.navigation {
  display: flex;
  flex-direction: column;
  padding: 20px;
  background-color: #ecf0f1; /* 导航栏的背景色 */

}

.nav-link {
  margin-bottom: 10px;
  text-decoration: none;
  color: #333;
  font-weight: bold;
  background-color: #7ed957; /* 导航按钮的背景色 */
  padding: 10px;
  border-radius: 5px; /* 圆角效果 */
  transition: background-color 0.3s; /* 添加过渡效果 */
}

.nav-link:hover {
  background-color: #5cba6e; /* 悬停时的背景色 */
}

.active-link {
  background-color: #4caf50; /* 当前激活的导航按钮背景色 */
}
</style>
