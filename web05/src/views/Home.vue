<template>
    <div>
      <h2>{{ pageTitle }}</h2>
      <!-- Add the specific content for Home.vue here -->
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        pageTitle: 'Home', // Adjust the title based on the page
      }
    },
    watch: {
      $route(to, from) {
        // Adjust the title based on the route
        this.pageTitle = to.name || 'Home';
      },
    }
  };
  </script>
  