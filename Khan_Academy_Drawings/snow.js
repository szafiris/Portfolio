var snow = [ ];
var count = 0;
var groundY = 375;
while (count < 300){
    var snowflake = {
        x: Math.floor(Math.random() * 400),
        y: Math.floor(Math.random() * 400),
        size: Math.floor(Math.random() * 11) + 2,
        dx: Math.random() * 2 + 1,
        dy: Math.floor(Math.random() * 6) + 1
    };
    snow[count] = snowflake;
    count = count + 1;
}

draw = function() {
    background(144, 230, 245);
    
    noStroke();
    
    ellipse(330, 350, 100, 100);
    ellipse(330, 300, 75, 75);
    ellipse(330, 250, 50, 50);
    stroke(5, 5, 5);
    strokeWeight(6);
    point(320, 250);
    point(340, 250);
    stroke(237, 148, 40);
    point(330, 260);
    
    fill(250, 250, 250);
    noStroke();
    
    var whichFlake = 0;
    while (whichFlake < 300){
        var snowflake = snow[whichFlake];
        ellipse(snowflake.x, snowflake.y, snowflake.size, snowflake.size);
        
        snowflake.x = snowflake.x + snowflake.dx;
        snowflake.y = snowflake.y + snowflake.dy;
        
        if (snowflake.x >= 400) {
            snowflake.x = 0;
        }
        if (snowflake.y >= 400) {
            snowflake.y = 0;
        }
        whichFlake = whichFlake + 1;
        
        rect(0, groundY, 400, 300);
        if (groundY > 50) {
            groundY = groundY - 0.00002;
        }
    
    }

};
