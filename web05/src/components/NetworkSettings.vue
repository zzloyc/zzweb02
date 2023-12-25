<template>
    <div>
      <!-- Content for NetworkSettings or ExperimentSettings -->
      <h2>{{ pageTitle }}</h2>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        pageTitle: 'Network Settings', // Change this dynamically based on the page
      };
    },
    watch: {
      $route(to, from) {
        // Adjust the title based on the route
        this.pageTitle = to.name || 'Page Title';
      },
    },
  };
  </script>
  