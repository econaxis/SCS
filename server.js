const http = require('http');
var formidable = require ('formidable'), util = require('util');
var fs = require('fs');
var jsonString ='';
var _PATH = "/Users/user/documents/github/SCS/";
console.log("path exists: " + fs.existsSync("./a.txt"));
console.log("2path exists: " + fs.existsSync("/Users/user/data"));
const server = http.createServer((request, response) => {
    console.log("Connection: " + request.url);
    if(request.method == 'POST') {
        fs.rename("~/test","~/test1", function (err) {
            if(err) console.log("error: "+ err);});


        var form = new formidable.IncomingForm();
        form.keepFilenames = true;
        form.on('file', function(name, file) {
            console.log("file received= " + name + "/ path is : "+ file.path);
            console.log("exists: "+ fs.existsSync(file.path));
            fs.rename(file.path, _PATH + "data/input.txt", function (err) {
                if(err) console.log("error: "+ err);
            });
        });
        response.setHeader("Access-Control-Allow-Origin", "*");
        response.setHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
        form.parse(request, function(err, fields, files) {
            console.log ("PARSING\n");
            response.writeHead(200, {'content-type': 'text/plain'});
            response.write("received\n\n\n");
            response.end();
        });
        // response.write(request.url);
        // response.write("connection achieved\n");
    }
});
server.listen(3000);
