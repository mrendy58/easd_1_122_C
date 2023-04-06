//1. karena dengan menggunakan algoritma akan mempermudah seseorang dalam mengidentifikasi dan juga menyelesaikan masalah secara terstruktur.
//2. data structur dibagi menjadi 2 yaitu data structur quadratic dan juga data structur loglinear
//3. tingkat kesulitan program,bahasa yang digunakan, mudah digunakan, dan juga kesimpelan sebuah program
//4. selection sort yang dimana berfungsi untuk mengseleksi data dari yang terkecil hingga terbesar sehingga mempercepat pengurutan.
//5. contoh algoritma yang masuk ke dalam quadratic yaitu bubblesort, insertionsort, selectionsort sedangkan yang masuk loglinear adalah quicksort,mergesort, shellsort.
//6. membuat program

#include <iostream>
using namespace std;

int ren[42];
int cmp_count;
int mov_count;
int n;


void input() {
    while (true)
    {
        cout << "Masukan Panjang element array :";
        cin >> n;

        if (n <= 42)
            break;
        else
            cout << "\nMasukan Panjang array adalah 42" << endl;

    }
    cout << "\n-------------------------" << endl;
    cout << "\nMasukan Element array" << endl;
    cout << "\n-------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> ren[i];

    }
}

void swap(int x, int y)
{
    int temp;

    temp = ren[x];
    ren[x] = ren[y];
   ren[y] = temp;
}
void q_short(int low, int high)
{
    int pivot, i, mr;
    if (low > high)
        return;



    pivot = ren[low];

    i = low + 1;
    mr = high;


    while (i <= mr)
    {

        while ((ren[i] <= pivot) && (i <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;


        while ((ren[mr] > pivot) && (mr >= low))
        {
            mr--;
            cmp_count++;
        }
        cmp_count;


        if (i < mr)
        {

            swap(i, mr);
            mov_count++;
        }
    }

    if (low < mr)
    {

        swap(low, mr);
        mov_count++;
    }

    q_short(low, mr - 1);


    q_short(mr + 1, high);

}

void display() {
    cout << "\n-----------------" << endl;
    cout << "\nSorted Array" << endl;
    cout << "\n-----------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << ren[i] << " ";
    }

    cout << "\n\nBanyak nya Perbandingan :" << cmp_count << endl;
    cout << "Jumlah Perpindahan Data :" << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);
    display();
    system("pause");

    return 0;
}