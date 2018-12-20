var url = "http://ip.jsontest.com/";
var result = undefined;
var isComplete = false;
function callback(text) {
    result = text;
    isComplete = true;

};
var xmlhttp = new XMLHttpRequest();

xmlhttp.onreadystatechange = function(){
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200){
       callback(xmlhttp.responseText);
}

}
xmlhttp.open("GET", url, true);
xmlhttp.send();
while(! isComplete );
result
