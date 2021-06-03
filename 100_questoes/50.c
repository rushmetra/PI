#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

char *mystrcpy(char s1[], const char s2[]) {
    char* result = s1;
    while((*s1 = *s2)) {
        s2++; 
        s1++;
    }
    return result;
}

int mystrcmp(char s1[], char s2[]) {
    while(*s1 == *s2 && *s1) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

char *mystrstr (char s1[], char s2[]) {
    char *ret = NULL;
    int i, j, l;
    
    if (!(*s2))
        ret = s1;

    for (i = 0; s1[i] && !ret; i++) {
        for (j = 0, l = i; s1[l] == s2[j] && s2[j]; l++, j++);
        if (!s2[j])
            ret = s1 + i;
    }
  
    return ret;
}

//11
void mystrrev(char s[]) {
    int len;
    for(len = 0; s[len]; len++);
    char rev[len];
    for(int i = 0; i < len; i++) rev[i] = s[len - i - 1];
    for(int i = 0; i < len; i++) s[i] = rev[i];
}

//12
int isVogal(char c) {
    int ans = 0;
    
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
    || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
        ans = 1;

    return ans;  
}

void strnoV (char s[]) {
    int i, j;

    for (i = 0; s[i]; i++) 
        if (isVogal(s[i])) {
            for (j = i; s[j]; j++) 
                s[j] = s[j+1];
            i--;
        }  
}

//13

void truncW (char t[], int n){
    int i, j, count = 0;
    for(i = 0; t[i]; i++) {
        if(t[i] != ' ')
            count++;
        else 
            count = 0;

        if(count > n) {
            for(j = i; t[j]; j++)
                t[j] = t[j+1];
            i--;
        }
    }

}

//14
int freqC(char ch, char s[]) {
    int freq = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == ch) freq++;
    }
    return freq;
}

char charMaisFreq(char s[]) {
    char maisFreq = 0;
    int freqMax = 0, freq;
    for(int i = 0; s[i]; i++) {
        if((freq = freqC(s[i],s)) > freqMax) {
            freqMax = freq;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

//15 

int iguaisConsecutivos (char s[]) {
    int resultado = 0, count = 1, i, j;

    for(i = 0; s[i]; i = ++j, count = 1) {
        for(j = i; s[j] == s[j+1]; j++) {
           count++; 
        }

        if(count > resultado) {
            resultado = count;
        }
    }

    return resultado;
}

// 16 

int ocorreu(char s[], int j, int n) {
    int i, ans = 0;
    for (i = j; i < n && !ans; i++)
        ans = s[i] == s[n];
    return ans;
}

int difConsecutivos(char s[]) {
    int i, j,count = 0, max = 0, flag = 1;
    for (i = 0; s[i]; i++, count = 0, flag = 1) {
        for (j = i; s[j] && flag; j++) {
            if (!ocorreu(s, i, j))
                count++;
            else 
                flag = 0;
        }
        if (count > max)
            max = count;
    }
    return max;
}

// 17 
int maiorPrefixo (char s1 [], char s2 []) {

    int i, count = 0;
    for(i = 0; s1[i] == s2[i]; i++) {
     count++;
    }

    return count;
}

// 18 
int maiorSufixo (char s1 [], char s2 []) {
    int i, j, ans = -1;
    for(i = 0; s1[i]; i++);
    for(j = 0; s2[j]; j++);
    while(s1[i--] == s2[j--]) ans++;
    return ans;
}

//19

int sufPref (char s1[], char s2[]) {
    
    int i , j;

    for (i = j = 0; s1[i]; i++) {
        
        if (s2[j] && s2[j] == s1[i]) j++;
        else j = 0;
        
    }
    
    return j;
}

//20

int contaPal (char s[]) {
    int ans = 0, i, inWord = 0;

    for(i = 0; s[i]; i++) {
     
        if(inWord && (s[i] == ' ' || s[i] == '\n')) inWord = 0;
        else if (!inWord && s[i] != ' ' && s[i] != '\n') {
            inWord = 1;
            ans++;
        }
    }
    return ans;
}

//21 - feita por mim sem ajudas :D
int contaVogais (char s[]) {
    int i, count = 0;
    for(i = 0; s[i]; i++) {

        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
        s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            count++;
        }
    }
    return count;
}
//22
int contida (char a[], char b[]) {
    int i, j, isContained = 1;

    for(i = 0; a[i] && isContained == 1; i++) {
        int pertence = 0;
        for(j = 0; b[j]; j++) {
            if(a[i] == b[j]) pertence = 1;
        }
        if(pertence == 0) {
            isContained = 0;
        }
    }

    return isContained;
}


// 23
int palindroma (char s[]) {
    int len = 0, i, ans = 1;

    for(i = 0; s[i]; i++) len++;
    for(i = 0; s[i]; i++) if(s[i] != s[len - 1 - i]) return 0;
    return 1;
}

//24
int remRep (char x[]) {
    int i, j;

    for (i = 0; x[i]; i++) {
        if (x[i] == x[i+1]) {
            for (j = i+1; x[j]; j++) 
                x[j] = x[j+1];
            i--;
        }
    }

    return i;
}

//25 CONSEGUI FAZER :D
int limpaEspacos (char texto[]) {
    int i, j;
    for(i = 0; texto[i]; i++) {
        if(texto[i] == texto[i + 1] && texto[i] == ' ') {
            for(j = i + 1; texto[j]; j++)
                texto[j] = texto[j+1];
            i--;    
        }
    }

    return i;
}

//26
void insere (int s[], int N, int x){
    int i, j;

    for(i = 0; i < N; i++) {
        if(s[i] >  x) {
            for(j = N; j > i; j--) {
                s[j] = s[j - 1];  
            }
            s[i] = x;
            break;
        }
        if(i == N - 1) s[N] = x;
    }
}

//27
void merge (int r [], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;
    while(k < na + nb) {
        if((a[i] < b[j] && i < na) || j >= nb)
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
}
//28

int crescente (int a[], int i, int j){
    int ans = 1;
    for (; i < j && ans; i++)
        ans = a[i] <= a[i+1];
    return ans;
}

//29
int retiraNeg (int v[], int N){
    int i, j, count = 0;
    for(i = 0; i < N; i++) {
        if(v[i] < 0) {
            for(j = i; j < N; j++)
                v[j] = v[j+1];
            i--;
            N--;
        }
    }
    return i;
}

//30 REVERRRRRRRRRRR
int menosFreq (int v[], int N) {
    int freq = 1, minFreq = N, ans = v[0], i;
    for(i = 1; i < N; i++) {
        if(v[i] == v[i - 1]) freq++;
        if(v[i] != v[i - 1]) {
            if(freq < minFreq) {
                minFreq = freq;
                ans = v[i - 1];
            }
            freq = 1;
        }
    }
    if(freq < minFreq) {
        minFreq = freq;
        ans = v[i - 1];
    }
    return ans;
}
// 31 
int maisFreq (int v[], int N){
       int freq = 1, maxFreq = 0, ans = v[0], i;
       for(i = 1; i < N; i++) {
           if(v[i] == v[i - 1]) freq++;
           if(v[i] != v[i - 1]) {
                if(freq > maxFreq) {
                    maxFreq = freq;
                    ans = v[i - 1];
                }
                freq = 1;
           }
       }
       if(freq > maxFreq) {
            maxFreq = freq;
            ans = v[i - 1];
    } 
    return ans;
}
// 32 Consegui fazer mais ou menos
int maxCresc (int v[], int N) {
    int i, j, ans = 1, temp = 1;

    for(i = 0; i < N; i++) {
        if(v[i] > v[i + 1]) {
          ans = temp > ans ? temp : ans;
          temp = 1;
        }
        else {
            temp++;
        } 
    }
    if(temp > ans) {
        ans = temp;
    }
    return ans;
}
// 33
int elimRep (int v[], int n) {
    int i, j, l;

    for (i = 0; i < n; i++) 
        for (j = i+1; j < n; j++) 
            if (v[i] == v[j]) {
                for (l = j; l < n; l++) 
                    v[l] = v[l+1];
                j--;
                n--;
            }

    return i;   
}

//34 
int elimRepOrd (int v[], int n) {

    int i, j, l;

    for (i = 0; i < n; i++) 
        for (j = i+1; j < n; j++) 
            if (v[i] == v[j]) {
                for (l = j; l < n; l++) 
                    v[l] = v[l+1];
                j--;
                n--;
            }

    return i;   
}
//35 
int comunsOrd (int a[], int na, int b[], int nb){
    int i = 0, j = 0, count = 0;

    while(i < na && j < nb) {
        if(a[i] == b[j]) {
            count++;
            i++;
            j++;
        } else if(a[i] > b[j]) j++;
        else i++; 
    }

    return count;
}
//36 Consegui fazer com ajuda
int comuns (int a[], int na, int b[], int nb) {
    int i, j, ans = 0;
    for(i = 0; i < na; i++) {
        int belongs = 0;
        for(j = 0; j < nb; j++) if(a[i] == b[j]) belongs = 1;
        if(belongs) ans++;
    }
    return ans;
}

//37 consegui com ajuda
int minInd (int v[], int n) {
   int r = -1, i;
   if(n < 1) {

   } else {
       r = 0;
       for(i = 1; i < n; i++) 
        if(v[i] < v[r]) 
           r = i;
        
   }
   return r;
}
//38 consegui com ajuda
void somasAc (int v[], int Ac [], int N){
    int i, r = 0;

    for(i = 0; i < N; i++) {
        r += v[i];
        Ac[i] = r;
    }
}
//39 consegui com ajuda
int triSup (int N, int m [N][N]) {
    int i, j, ans = 1;

    for(i = 0; i < N && ans; i++) {
        for(j = 0; j < i; j++) {
            if(i > j) ans = m [i][j] == 0;
            else ans = 0;
        }
    }

    return ans;
}
//40
void transposta (int N, float m [N][N]) {
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//41 FACIL AHAHA
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i, j;

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

//42  facil 
  int unionSet (int N, int v1[N], int v2[N], int r[N]){
             int c;
      for(c = 0; c < N; c++) {
          if(v1[c] || v2[c]) r[c] = 1;
          else r[c] = 0; // ou r[c] = v1[c] || v2[c] 
      }

      return c;
}

//43 facil
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
      int c;
      for(c = 0; c < N; c++) {
          if(v1[c] == 1 && v2[c] == 1) r[c] = 1;
          else r[c] = 0; // ou r[c] = v1[c] && v2[c] 
      }

      return c;
}
//44 mais ou menos
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int c = 0;
    for(c = 0; c < N; c++) {
        r[c] = v1[c] < v2[c] ? v1[c] : v2[c];
    }
       return c;
   }
//45 mais ou menos, dps da 44 foi facil
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
     int c = 0;
    for(c = 0; c < N; c++) {
        r[c] = v1[c] > v2[c] ? v1[c] : v2[c];
    }
     return c;
}
//46 facil 
int cardinalMSet (int N, int v[N]){
   	  int c=0, res = 0;
    for(c = 0; c < N; c++) {
        res += v[c];
    }
return res;
}
//47 tinha o raciocinio certo mas n sabia o inicial.y
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {int x, y;} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int c;
    for(c = 0; c < N; c++) {
        Movimento x = mov[c];
        if(x == Norte) inicial.y++;
        if(x == Sul) inicial.y--;
        if(x == Oeste) inicial.x--;
        if(x == Este) inicial.x++;
    }
    return inicial;
}
//48 dificil perceber a condiçao do for mas o resto entendi
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int c, r = -1;
    for(c = 0; c < N && !(inicial.y == final.y && inicial.x == final.x); c++) {
        if(inicial.y > final.y) {
            mov[c] = Sul;
            inicial.y--;
        } else if(inicial.y < final.y) {
            mov[c] = Norte;
            inicial.y++;
        } else if(inicial.x > final.x) {
            mov[c] = Oeste;
            inicial.x--;
        } else if(inicial.x < final.x) {
            mov[c] = Este;
            inicial.x++;
        } else {}
    }

    if(inicial.y == final.y && inicial.x == final.x)
        r = c;
    return r;
}
//49 
typedef struct posicao {
    int x, y;
} Posicao;

int maiscentral (Posicao pos[], int N) {
    int i, closest, dist, r = 0;
    for(i = 0; i < N; i++) {
        dist = pow(pos[i].x, 2) + pow(pos[i].y, 2);
        if(dist < closest || !i) {
            closest = dist;
            r = i;
        } 
    }
    
    return r;
}
//50
int iguais(Posicao p1, Posicao p2) {
    return p1.y == p2.y && p1.x == p2.x;
}
int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, count = 0;
    for (i = 0; i < N; i++) 
        count += pow(pos[i].x - p.x, 2) + pow(pos[i].y - p.y, 2) < 2 && !iguais(p, pos[i]);
    return count;
}
