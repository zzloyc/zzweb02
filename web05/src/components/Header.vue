<template>
    <div class="header">
      <h1>{{ systemName }}</h1>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        systemName: 'Your System Name',
      };
    },
  };
  </script>
  
  <style>
  .header {
    background-color: #3498db;
    color: #fff;
    padding: 10px;
  }
  </style>
  