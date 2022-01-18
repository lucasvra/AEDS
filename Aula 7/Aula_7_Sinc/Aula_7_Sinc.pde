import java.time.*;

float x, y;
float vx = 2, vy = 3;

float p1y = 0, p2y = 0;

void setup()
{
  size(600, 600);
  background(255);
  frameRate(60);
}

void draw()
{
  background(255);
  //print(LocalDate.now());
  String[] arr = {str(LocalDate.now().getDayOfMonth()), str(LocalDate.now().getMonthValue()), str(LocalDate.now().getYear())};
  fill(0);
  textSize(60);
  text(join(arr,"/"),50, 50);
  stroke(#E81CD1);
  strokeWeight(10);
  fill(#1FC418);
  ellipse(x, y, 50, 50);
  
  int res = soma(5, 10);
  
  stroke(0);
  strokeWeight(1);
  fill(#CFD39E);
  
  if(mouseX < width/2)
  {
    p1y = mouseY;
    p2y = p2y + 0.5*vy;
  }
  else
  {
    p2y = mouseY;
    //p1y = p1y + 0.5*vy;
  }
  
  if(keyPressed && key == 'w')
  {
    p1y-= 5;
  }
  
  if(keyPressed && key == 's')
  {
    p1y+= 5;
  }
  
  
  rect(50, p1y, 10, 100);
  rect(width-50, p2y, 10, 100);
    
  x += vx;
  y += vy;
  
  if(x < 0 || x > width) vx = -vx;
  if(y < 0 || y > height) vy = - vy;
  
  if(x > width-50 && x < width-50+10 && y > p2y && y < p2y+100) vx = -vx;
  if(x > 50 && x < 50+10 && y > p1y && y < p1y+100) vx = -vx;
  
}

int soma(int x, int y)
{
  return x + y; 
}
