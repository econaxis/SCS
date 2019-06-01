//dsds
var text;
var filereader = new FileReader();
$(document).ready(function(){
    var text = $("#name").val();
    var url;
    $( '#load-file' ).click( function () {
        if ( ! window.FileReader ) {
            return alert( 'FileReader API is not supported by your browser.' );
        }
        var $i = $( '#name' ), // Put file input ID here
            input = $i[0]; // Getting the element from jQuery
        var file = input.files[0]; // The file
        var fr = new FileReader(); // FileReader instance
        if(!input.files || !input.files[0]) {
            console.log ("Bad\n");
        }
        var text="first";
        fr.onload= function () {
            console.log("called: " + fr.result);
            text = fr.result;
            console.log ( "result: " + text );
            url = "http://localhost:3000/" + text;
            $.get(url, function(data, status){
                alert("Data: " + data + "\nStatus: " + status);
            });
        }
        fr.readAsText( file );
    } );
    $("button").click(function(){
    });
});
