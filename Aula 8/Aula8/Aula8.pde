int[] arr = {23, 4, 67, 1, 90, 54, 21, 50};
int pos1 = -1, pos2 = -1, posPivo = -1;

void setup()
{
   size(600,600);
   background(255);
   thread("Executa");
}

void Executa()
{
  delay(1000);
  QuickSort(arr);
}

void draw()
{
   background(255);
   int N = arr.length;
   float base = width/N;
   
   for(int i = 0; i < N; i++)
   {
     if(i == posPivo) fill(#FAFF00);
     else if(i >= pos1 && i <= pos2) fill(0, 0, 255);
     else fill(0, 255, 0);
     
     int h = arr[i] * 5;
     rect(i*base, height - h, base, h);
   }
}

void BubbleSort(int[] V)
{
  int fim = V.length;
  Boolean continua = false;
  do
  {
    continua = false;
    for(int i = 0; i < fim-1; i++)
    {
      pos1 = i;
      pos2 = i+1;
      delay(1000);
      
      
      if(V[i] > V[i+1])
      {
         int aux = V[i];
         V[i] = V[i+1];
         V[i+1] = aux;
         continua = true;
      }
    }
    fim--;
  }while(continua);
  
  pos1 = -1;
  pos2 = -1;
}

int Particiona(int[] V, int inicio, int fim)
{
    int esq = inicio, dir = fim;
    int pivo = V[inicio];
    
    while(esq < dir)
    {
       while(esq <= fim && V[esq] <= pivo) esq++;
       while(dir >= 0 && V[dir] > pivo) dir--;
       
       delay(1000);
       
       if(esq < dir)
       {
          int aux = V[esq];
          V[esq] = V[dir];
          V[dir] = aux;
       }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void QuickSort(int[] V, int inicio, int fim)
{
   if(fim <= inicio)
   {
     posPivo = -1;
     pos1 = -1;
     pos2 = -1;
     return;
   }
   
   int pivo = Particiona(V, inicio, fim);
   pos1 = inicio;
   pos2 = fim;
   posPivo = pivo;
   delay(1000);
   
   QuickSort(V, inicio, pivo-1);
   QuickSort(V, pivo+1, fim);
}

void QuickSort(int[] V)
{
   QuickSort(V, 0, V.length-1); 
}
