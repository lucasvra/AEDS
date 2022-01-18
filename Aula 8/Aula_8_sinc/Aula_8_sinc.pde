int n = 10;
int[][] grid = new int[n][n];

void setup()
{  
  frameRate(5);
  size(600,600);
  background(255);
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
       grid[i][j] = (int)random(5); 
    }    
  }
  
}

void draw()
{
  background(255);
  float l = width/n;
  float h = height/n;
  
  for(int i =0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      float y = i*h;
      float x = j*l;
      
      if(grid[i][j] == 0) fill(255);
      else if(grid[i][j] == 1) fill(0);
      else if(grid[i][j] == 2) fill(255,0,0);
      else if(grid[i][j] == 3) fill(#E5C833);
      else fill(0,255,0);
      
      rect(x, y, l, h);
      textAlign(CENTER,CENTER);
      fill(0);
      text(grid[i][j], x+l/2, y+h/2);
    }
  }
}
