const fs = require('fs');

var app = new Vue({
	el: '#app',
	data: {
		title: 'Xampp Manager',
		sudoPassword: '',
    installed_status: false,
    running_status: false
	},
	methods: {
    getUnits: function(){
      if (fs.existsSync("/opt/lampp/xampp")){
        this.installed_status = true;
      }
      // check for if it's runnin'
    },
		checkPassword(input){
			return true;
		}
		/*checkPassword(input){
			if (input == "" || input == " " || input == null){
				return false;
			} else {
				return true;
			}
		}*/
	},
  created: function(){
    this.getUnits();
  }
});
