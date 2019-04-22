var plane = {x: 10, y: 30, WH: 50}; 
var groundY = 350;
var cloudX = 300;

draw = function() {
    background(176, 236, 237);
    
    // Sun
    fill(251, 255, 0);
    ellipse(350, 50, 50, 50);
    
    // Cloud
    fill(252, 249, 249);
    ellipse(cloudX, 75, 50, 50);
    ellipse(cloudX + 20, 65, 50, 50);
    ellipse(cloudX + 40, 75, 50, 50);
    
    // Runway
    noStroke();
    fill(111, 255, 0);
    rect(0, groundY, 400, 300);
    fill(0, 0, 0);
    rect(0, groundY + 50, 400, 50);
    
    // Plane
    image(getImage("space/beetleship"), plane.x, plane.y, plane.WH, plane.WH);
   
    if (groundY > 200){
        groundY = groundY - 0.1;
        plane.y = plane.y + 0.1;
        plane.x = plane.x + 1;
        plane.WH = plane.WH + 0.05;
    }
    
    if (plane.x > 400){
        plane.x = plane.x - 480;
    }
    
    cloudX = cloudX + 0.01;
    
    if (cloudX > 420){
        cloudX = cloudX - 490;
    }
    
};
