var sh = require("shelljs");

var RootDirectory = "../";

// error messages
function error(errorMessage){
  if (errorMessage == "nullSudo"){
    alert("Sudo password can't be null!");
  } else {
    alert("There is an error but I don't even know what it is about :/");
  }
  return;
}

// xampp functions
function xampp(option){
  var sudoPassword = document.getElementById("input-sudo-password").value;
  if (sudoPassword == null || sudoPassword == "" || sudoPassword == " "){
    error("nullSudo");
  } else {
    if (option == "start"){
    	sh.exec(RootDirectory + "xampp-manager --sudo-login " + sudoPassword + " --start-all-services");
		} else if (option == "stop"){
    	sh.exec(RootDirectory + "xampp-manager --sudo-login " + sudoPassword + " --stop-all-services");
		} else if (option == "install"){
			sh.exec(RootDirectory + "xampp-manager --sudo-login " + sudoPassword + " --install-xampp");
		} else if (option == "remove"){
			sh.exec(RootDirectory + "xampp-manager --sudo-login " + sudoPassword + " --remove-xampp");
		}
  }
  return;
}

function Git(){
  sh.exec("xdg-open https://gitlab.com/anilademyener/xampp-manager.git");
  return;
}

function UpdateManager(){
  alert("Soon!");
  return;
}

function StartAllServices(){
  xampp("start");
  return;
}

function StopAllServices(){
  xampp("stop");
  return;
}

function OpenFolder(){
	sh.exec("xdg-open /opt/lampp/htdocs");
  return;
}

function InstallXampp(){
	if (confirm("That process will install x64 only for Linux systems!")){
		xampp("install");
	}
	return;
}

function RemoveXampp(){
	if (confirm("That process will remove Xampp from your system!")){
		xampp("remove");
	}
	return;
}
