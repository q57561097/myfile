<template>
  <div>
  <div id="progress" class="progress progressData">
    <div class="progress-bar progress-bar-success" role="progressbar"
         style="width: 40%;" id="success">
    </div>
    <div class="progress-bar progress-bar-info" role="progressbar"
         style="width: 30%;" id="info">
    </div>
    <div class="progress-bar progress-bar-warning" role="progressbar"
         style="width: 20%;" id="warning">
    </div>
  </div>
    <div id="end" class="precent">6</div>
  <div id="start" class="precent"  @mousedown="first_down($event)" @mousemove="start_move($event)" @mouseup="first_up($event)" ref="firstbar">588</div>
  </div>
</template>

<script>
	export default {
		name: "mouse",
    data(){
		  return {
		    first: false,
        end: false}
            },
    methods: {
		  start_move(e){
		    console.log(this.first)
        if (this.first) {
          let start = document.getElementById('start');
          let end = document.getElementById('end');
          let success = document.getElementById('success');
          let info = document.getElementById('info')
          let warning = document.getElementById('warning');
          let progress = document.getElementById('progress');
          let start_width = e.pageX - progress.offsetLeft;
          if (start_width >= progress.offsetWidth){
            start_width = progress.offsetWidth
          }
          let end_width = info.offsetWidth;
          if (start_width + end_width >= progress.offsetWidth){
            end_width = progress.offsetWidth - start_width
          }
          let fina = progress.offsetWidth - start_width - end_width;
          success.style.width = start_width + "px";
          info.style.width = end_width + "px";
          warning.style.width = fina + "px";
          start.style.marginLeft = start_width - start.offsetWidth /2 + "px";
          end.style.marginLeft = start_width + end_width - end.offsetWidth /2 + "px";
          console.log([start_width, start.offsetWidth, 68888888888])}

      },
      first_down(e){
          this.first = true
      },
      end_down(e){
		    this.end = true
      },
      first_up(e){
        this.first = false
      },
      end_up(e){
        this.end = false
      }
    }
	}
</script>

<style scoped>
  .precent
  {
    position: absolute;
    top:50px;
    z-index: 1000;
    background-color: #fff;
    width: 30px;
    height: 30px;
    line-height: 30px;
    border-radius: 30px;
    border:1px solid #ccc;
    cursor: pointer;
  }
  .progressData
  {
    /*margin-top:;*/
    line-height: 0;
    height: 20px;
    width: 80%;
  }

</style>
