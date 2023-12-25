<!-- Header.vue -->
<template>
    <div class="header">
      <div class="logo">系统名称</div>
      <div class="buttons">
        <button @click="handleSystemSettings">系统设置</button>
        <button @click="handlePersonalSettings">个人设置</button>
      </div>
    </div>
  </template>
  
  <script>
  export default {
    methods: {
      handleSystemSettings() {
        this.$router.push('/system-settings');
      },
      handlePersonalSettings() {
        this.$router.push('/personal-settings');
      },
    },
  };
  </script>
  
  <style scoped>
  .header {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 10px;
    background-color: #3498db;
    color: #fff;

  }
  
  .logo {
    font-size: 24px;
    font-weight: bold;
  }
  
  .buttons button {
    margin-left: 10px;
    padding: 8px 12px;
    background-color: #2ecc71; /* 按钮的背景色 */
    color: #fff;
    border: none;
    cursor: pointer;
  }
  
  .buttons button:hover {
    background-color: #27ae60;
  }
</style>