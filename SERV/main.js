//dsds
var text;
var filereader = new FileReader();
$(document).ready(function(){
    var text = $("#name").val();
    var url;
    $( '#load-file' ).click( function () {
        var formD = new FormData();
        formD.append('file', $("#name").get(0).files[0])
        var _url = $('#url').val();
        $.ajax({
            url:_url,
            data: formD,
            processData: false,
            contentType: false,
            type: 'POST',
            success: function(data) {
                $("#ls").append(data);
            }
        })
        // $.post("http://localhost:3000", formD, function(data) {
        //     $("#ls").append(data);
        //     alert("alert: " + data);
        // })
    } );
$("button").click(function(){
});
});
