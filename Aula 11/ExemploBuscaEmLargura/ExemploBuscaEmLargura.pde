import java.util.*;

int n = 10;
int[][] M = new int[n][n];
Queue<Integer> fila = new LinkedList<Integer>();
int contador = 0;

int ia = -1, ja = -1;

void setup()
{
  size(600,600);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      M[i][j] = 0;
      
  thread("executa");
}

void executa()
{
  //buscaEmLargura(5*n+5); 
  M[8][5] = 1;
  M[2][2] = -3;
  
  wavefront();
}

void wavefront()
{
    boolean fim = false;
    while(!fim)
    {
        for(int i = 0; i < n; i++)
        {
          for(int j = 0; j < n; j++)
          {
            ia = i; ja = j;
            if(M[i][j] > 0) continue;
            delay(100);
            
            if(i+1 < n  && M[i+1][j] > 0) M[i][j] = M[i+1][j] + 1; 
            if(i-1 >= 0 && M[i-1][j] > 0) M[i][j] = M[i-1][j] + 1;
            if(j+1 < n  && M[i][j+1] > 0) M[i][j] = M[i][j+1] + 1;
            if(j-1 >= 0 && M[i][j-1] > 0) M[i][j] = M[i][j-1] + 1;
            
            if(M[i][j] > 0 && (
               i+1 < n  && M[i+1][j] == -3
            || i-1 >= 0 && M[i-1][j] == -3
            || j+1 < n  && M[i][j+1] == -3
            || j-1 >= 0 && M[i][j-1] == -3  ))
            {
             fim = true;
             break;
            }
            
          } 
          if(fim) break;
        }       
    }
    
}

void buscaEmLargura(int origem)
{
  // i,j -> i*n+j = v
  // v/n = i
  // v%n = j
  
  fila.clear();
  fila.add(origem);
  
  while(fila.size() > 0)
  {
    delay(100);
    int v = fila.poll();
    int iv = v/n;
    int jv = v%n;
    
    if(M[iv][jv] != 0) continue; //já foi visitado
    
    M[iv][jv] = ++contador;
    
    if(iv+1 <  n) fila.add((iv+1)*n+jv);
    if(iv-1 >= 0) fila.add((iv-1)*n+jv);
    if(jv+1 <  n) fila.add((iv)*n+jv+1);
    if(jv-1 >= 0) fila.add((iv)*n+jv-1);
  }
}

void draw()
{
  background(0);
  float largura = width / n;
  float altura = height / n;
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      float y = i * largura;
      float x = j * altura;
      if(i == ia && j == ja) fill(#90BFFF);
      else fill(255-M[i][j]*10);
      rect(x, y, largura, altura);
         
      fill(M[i][j]*10);
      textAlign(CENTER, CENTER);
      text(M[i][j], x + largura / 2, y + altura/ 2);
    }
  }
}
