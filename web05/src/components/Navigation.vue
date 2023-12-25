<template>
  <div class="navigation">
    <button @click="changePage('network')" class="styled-button">网络设置</button>
    <button @click="changePage('experiment')" class="styled-button">实验设置</button>
    <!-- Add more buttons as needed -->
  </div>
</template>

<script>
export default {
  props: ['changePage'],
};
</script>

<style>
.navigation {
  width: 10%;
  background-color: #2c3e50;
  padding: 10px;
  color: #fff;
  display: flex;
  flex-direction: column;
  box-sizing: border-box;
}

.styled-button {
  margin-bottom: 10px;
  cursor: pointer;
  background-color: #8bc34a; /* 浅绿色的背景 */
  color: #fff;
  border: none;
  padding: 8px;
  border-radius: 5px; /* 圆角边框 */
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); /* 阴影效果 */

  transition: background-color 0.3s, transform 0.1s; /* 过渡效果 */

  /* 按钮之间的间距 */
  &:not(:last-child) {
    margin-bottom: 10px;
  }

  /* 悬停时的样式 */
  &:hover {
    background-color: #689f38; /* 悬停时的浅绿色 */
  }

  /* 点击时的样式 */
  &:active {
    transform: scale(0.95);
  }
}
</style>
