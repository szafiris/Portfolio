background(186, 169, 194);
var square = {x: 100, y: 60};
var squareW = 20;
var squareH = 30;
var midHeight = 15;
var columnCount = 3;
var rowCount = 3;
var dx = 20;
var dy = 15;
var rowStartX = square.x;
var rowStartY = square.y;

for (var row = 0; row < rowCount; row += 1) {
    for (var column = 0; column < columnCount; column += 1) {
        quad(
            square.x, square.y,
            square.x + squareW, square.y + midHeight,
            square.x, square.y + squareH,
            square.x - squareW, square.y + midHeight
        );
        square.x += dx;
        square.y += dy;
    }
    
    square.x = rowStartX - dx;
    rowStartX = square.x;
    square.y = rowStartY + dy;
    rowStartY = square.y;
}

fill(3, 255, 3);

square = {x: 100, y: 150};
squareW = 20;
squareH = 30;
midHeight = 15;
columnCount = 3;
rowCount = 3;
dx = 20;
dy = 15;
rowStartX = 100;
rowStartY = 145;

for (row = 0; row < rowCount; row += 1) {
    for (column = 0; column < columnCount; column += 1) {
        quad(
            square.x, square.y,
            square.x + squareW, square.y - midHeight,
            square.x + squareW, square.y + midHeight - 5,
            square.x, square.y + squareH - 5
       );
        square.x += dx;
        square.y -= dy;
    }
    
    square.x = rowStartX;
    rowStartX = square.x;
    square.y = rowStartY + squareH;
    rowStartY = rowStartY + squareH - 5;
}

fill(252, 5, 5);

square = {x: 60, y: 120};
squareW = 20;
squareH = 25;
midHeight = 15;
columnCount = 3;
rowCount = 3;
dx = 20;
dy = 15;
rowStartX = 60;
rowStartY = 120;

for (row = 0; row < rowCount; row += 1) {
    for (column = 0; column < columnCount; column += 1) {
        quad(
            square.x, square.y,
            square.x - squareW, square.y - midHeight,
            square.x - squareW, square.y + midHeight - 5,
            square.x, square.y + squareH
        );
        square.x += dx;
        square.y += dy;
    }
    
    square.x = rowStartX;
    rowStartX = square.x;
    square.y = rowStartY + squareH;
    rowStartY = rowStartY + squareH;
}
