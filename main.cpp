

#include <iostream>
using namespace std;

//first_fit algorithim
void First_Fit(int*Add_blocks, int blocks_size, int* Add_process, int process_size)
{
    int* Array = new int[process_size];
    for (int i = 0; i < process_size; i++)
    {
        Array[i] = -1;
    }
    for (int i = 0; i < process_size; i++)
    {
        for (int j = 0; j < blocks_size; j++)
        {
            if (Add_blocks[j] >= Add_process[i])
            {
                Array[i] = j;
                Add_blocks[j] = 0;
                break;

            }
        }

    }
    
    //if the the processes greater than the block size

    for (int i = 0; i < process_size; i++)
    {
        cout << " " << i + 1 << "\t\t " << Add_process[i] << "\t\t ";
        if (Array[i] != -1)
        {
            cout << Array[i] + 1;
        }
        else
        {
            cout << "Not located";
        }
        cout << "\n";
    }

}

//bestes fit algorithim

void Best_Fit(int* Add_blocks, int blocks_size, int* Add_process, int process_size)
{
    int* Array = new int[process_size];

    for (int z = 0; z < process_size; z++)
    {
        Array[z] = -1;
    }

    for (int i = 0; i < process_size; i++)
    {
        // searching for the best index 
        int Best_Index = -1;
        for (int j = 0; j < blocks_size; j++)
        {
            if (Add_blocks[j] >= Add_process[i])
            {
                if (Best_Index == -1)
                    Best_Index = j;
                else if (Add_blocks[Best_Index] > Add_blocks[j])
                   Best_Index = j;
            }
        }

        
        if (Best_Index != -1)
        {
             
            Array[i] = Best_Index;

            
            Add_blocks[Best_Index] -= Add_process[i];
        }
    }

    cout << "\n process No. \t process size \t block no.\n";
    for (int i = 0; i < process_size; i++)
    {
        cout << " " << i + 1 << "\t\t" << Add_process[i] << "\t\t";
        if (Array[i] != -1)
        {
            cout << Array[i] + 1;
        }
        else
        {
            cout << "Not located";
        }
        cout << "\n";
    }
}

void Worst_Fit(int* Add_blocks, int blocks_size, int* Add_process, int process_size)
{
    int* Array = new int[process_size];

    for (int b = 0; b < process_size; b++)
    {
        Array[b] = -1;
    }

    for (int i = 0; i < process_size; i++)
    {
       
        int Worst_Index = -1;
        for (int j = 0; j < blocks_size; j++)
        {
            if (Add_blocks[j] >= Add_process[i])
            {
                if (Worst_Index == -1)
                    Worst_Index= j;
                else if (Add_blocks[Worst_Index] < Add_blocks[j])
                    Worst_Index = j;
            }
        }

        
        if (Worst_Index != -1)
        {
          
            Array[i] = Worst_Index;
              // avalibilty of the blocks
           Add_blocks[Worst_Index] = 0;
        }
    }
    //if the the processes greater than the block size
    cout << "\n process No. \t process size \t block no.\n";
    for (int i = 0; i < process_size; i++)
    {
        cout << " " << i + 1 << "\t\t" << Add_process[i] << "\t\t";
        if (Array[i] != -1)
        {
            cout << Array[i] + 1;
        }
        else
        {
            cout << "Not located";
        }
        cout << "\n";
    }
}





int main()
{
    
    cout << " Please enter the number of the blocks ";
    //number of the block
    int blocks; 
    //filling the block array
    int blocks_array;
    //put the size of the block
    cin >> blocks; 
    int* block = new int[blocks]; //block
    cout <<  "Please fill the block array";
    // filling the block array by user inputs
    for (int i = 0; i < blocks; i++) 
    {
        cin >> blocks_array;
        block[i] = blocks_array;
    }
    cout << " Please enter the number of the processes";
    //number of the processes
    int processes;
    //filling the processes array
    int processes_array;
    //put the size of the processes
    cin >> processes;
    int* process = new int[processes];
    cout << " Please fill the process array";
    for (int i = 0; i < processes; i++) 
    {
        cin >> processes_array;
        process[i] = processes_array;
    }
    // choosing  the fit algorithim 
    cout << "please choose F for first fir , B for best fit , W for worst fit" << endl;
    char choice;
    cin >> choice;
    if (choice == 'F')
    {
        First_Fit(block, blocks, process, processes);
    }
    else if (choice == 'B')
    {
        Best_Fit(block, blocks, process, processes);

    }
    else if (choice == 'W')
    {
        Worst_Fit(block, blocks, process, processes);
    }
    else
    {
        cout << "invalid choice" << endl;
    }
    
}

