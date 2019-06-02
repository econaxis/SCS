const http = require('http');
var formidable = require ('formidable'), util = require('util');
var fs = require('fs'), {execFile} = require ('child_process');
var jsonString ='';
const server = http.createServer((request, response) => {
    var _PATH = "/Users/user/documents/github/SCS/", output;
    console.log("Connection: " + request.url);
    response.setHeader("Access-Control-Allow-Origin", "*");
    response.setHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    response.writeHead(200, {'content-type': 'text/plain'});
    if(request.method == 'POST') {
        var form = new formidable.IncomingForm();
        form.parse(request, function(err, fields, files) {});



        form.on('file', function(name, file) {
            fs.rename(file.path, _PATH + "data/" + file.name, function (err) { if(err) console.log("error: "+ err); });
            _PATH +="data/" + file.name;
            console.log(_PATH);
            child = execFile('/Users/user/documents/github/SCS/bin/SCS', [_PATH], (error, stdout, stderr)=> {
                if(stderr) {
                    response.write("-1\n", function (err) {response.end()});
                    console.log ("error: " + error);
                }
                response.write("0\n" + stdout , function (err) {
                    response.end();
                });
            });
        });
        // response.write(request.url);
        // response.write("connection achieved\n");
    }
});
server.listen(3000);
