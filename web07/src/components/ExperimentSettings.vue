<template>
  <div class="experiment-settings">
    <div class="form-container">
      <textarea v-model="inputValue" placeholder="输入内容"></textarea>
      <button @click="submitForm">提交</button>
    </div>
    <div class="display-container">
      <div class="display-box">
        <p>{{ displayText }}</p>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'; // 引入axios
export default {
  data() {
    return {
      inputText: '',    // 输入框中的文本
      displayText: '',  // 展示框中的文本
    };
  },
  methods: {
  submitForm() {
    // 在按钮点击时触发，可以在这里处理输入并更新展示框的内容
    this.displayText = this.inputText;
  
    // 使用axios发送POST请求到后端
    axios.post('/cgi-bin/main', {
      inputText: this.inputText,
    })
    .then(response => {
      console.log('Success:', response.data);
      // 可以根据后端返回的数据进行相应操作
    })
    .catch(error => {
      console.error('Error:', error);
      // 处理错误情况
    });
  },
},
};
</script>

<style>
.experiment-settings {
  background-color: #b3e0f2; /* 淡蓝色背景 */
  padding: 20px;
  width: 100%; /* 让整个组件占据父容器的宽度 */
  box-sizing: border-box; /* 确保 padding 不会使宽度超过100% */
}

.form-container {
  display: flex;
  align-items: center; /* 垂直居中 */
  justify-content: space-between; /* 平均分配空间 */
  margin-bottom: 20px;
}

textarea {
  width: 90%; /* 输入框宽度 */
  padding: 10px;
  margin-right: 10px;
  border: 1px solid #64b5f6;
  border-radius: 5px;
  resize: vertical; /* 允许垂直调整大小 */
}

button {
  padding: 12px 15px; /* 增加按钮的高度 */
  background-color: #3498db; /* 按钮背景色 */
  color: #fff;
  border: none;
  cursor: pointer;
}

.display-container {
  width: 100%; /* 让展示框占据整个宽度 */
  display: flex;
  justify-content: center;
}

.display-box {
  padding: 15px; /* 增加展示框的高度 */
  margin-top: 10px;
  width: 100%; /* 让展示框占据整个宽度 */
  height: 330px;
  background-color: #ffffff; /* 按钮背景色 */
}

.display-box p {
  margin: 0;
}
</style>