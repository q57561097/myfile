const job = {"name": 1, "total": 500, "status": 0}
let a = "配置";
let b = "停止";
let c = "解绑";
let status1 = "配置中";
let status2 = "运行中";
let status3 = "待启动";
let result ;
let status;
if (job.total_time){
	result = a;
	status = status1;
}
else {
	if (job.total){
		result = b;
	}
	else {
		result = c;
	}
	if (job.status === 0){
		status = status3;
	}
	else {
		status = status2
	}

}
console.log(result);
