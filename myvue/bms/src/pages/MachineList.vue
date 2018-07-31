<template>
    <div class="machine">
      <div class="title"></div>
      <div class="border content"></div>
      <div class="border botton">

      </div>
    </div>
</template>

<script>
	export default {
		name: "MachinList"
	}
</script>

<style scoped>
    .machine
    {
      height: 200px;
      width: 100px;
    }
  .title
  {
    height: 10%;
    background: #000000;
    border-top-left-radius: 25px;
    border-top-right-radius: 25px;

  }
  .border
  {
    border: 1px solid #000000;
  }
  .content
  {
    height: 15%;
  }
  .botton
  {
    height: 75%;
    border-bottom-left-radius: 25px;
    border-bottom-right-radius: 25px;
    border-top: 0px;
  }

</style>
