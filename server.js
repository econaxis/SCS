const http = require('http');
const server = http.createServer((request, response) => {
    console.log("Connection: " + request.url);
    response.setHeader("Access-Control-Allow-Origin", "*");
    response.setHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    response.write(request.url);
    response.end();
});
server.listen(3000);
