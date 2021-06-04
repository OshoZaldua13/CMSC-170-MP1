#include <iostream>
#include <list>

using namespace std;

class Node{
public:
    Node();
    Node(int[]);
    list<Node*> children;
    Node *parent;
    int puzzle[9];
    int x;
    void setPuzzle(int[]);
    bool goalTest();
    void moveLeft(int[], int); 
    void moveRight(int[], int); 
    void moveUp(int[], int); 
    void moveDown(int[], int); 
    void copyPuzzle(int[], int[]);
    void printPuzzle();
    bool samePuzzle(int[]);
    void moveAllDirections();

};

class UninformedSearch{
public:
    UninformedSearch();
    list<Node*> breadthFirstSearch(Node*);
    //bool containsPuzzle(list<Node*>, Node*);
};

int main(){
    int array[9] = {
        1, 2, 4,
        3, 0, 5,
        7, 6, 8
    };

    Node root(array);
    UninformedSearch ui;

    list<Node*> solution = ui.breadthFirstSearch(&root);
    if(solution.size()>0){
        for(list<Node*>::iterator it=solution.begin();it!=solution.end();++it)
            (*it)->printPuzzle();
    }
    else
        cout << "NO SOLUTION WAS FOUND\n";
}

Node::Node(){
    parent = NULL;
    x = 0;
    for(int i=0;i<9;i++)
        puzzle[i] = 0;
}

Node::Node(int arr[9]){
    setPuzzle(arr);
    parent = NULL;
    x = 0;
}

 void Node::setPuzzle(int arr[9]){
     for(int i=0;i<9;i++)
        puzzle[i] = arr[i];
 }

 bool Node::goalTest(){ //check if na solve na ba ang puzzle
    for(int i=0;i<9;i++)
        if(puzzle[i]!=i)
            return false;
    return true;
}

void Node::copyPuzzle(int p1[9], int p2[9]) {
    for(int i=0;i<9;i++) //gicopy ra jud ang array
        p1[i] = p2[i];
}

void Node::moveLeft(int arrPuzzle[9], int i){
    if(i%3 > 0) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle); //copy para dili mawala
        newArrPuzzle[i] = newArrPuzzle[i-1];
        newArrPuzzle[i-1] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child); //gi add sa list of children
        child->parent = this; //gi set nga mao ni ang parent ani nga child
    }
}

void Node::moveRight(int arrPuzzle[9], int i){ //same ra ang nahitabo sa moveLeft pero sa right lang ni
    if(i%3 < 2) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i+1];
        newArrPuzzle[i+1] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }
}

void Node::moveUp(int arrPuzzle[9], int i){ //same ra pud pero up ni duhhh
    if(i-3 >= 0) {
       int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i-3];
        newArrPuzzle[i-3] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }
}

void Node::moveDown(int arrPuzzle[9], int i){ //again same
    if(i +3 < 9) {
        int newArrPuzzle[9];
        copyPuzzle(newArrPuzzle, arrPuzzle);
        newArrPuzzle[i] = newArrPuzzle[i+3];
        newArrPuzzle[i+3] = 0;

        Node* child = new Node(newArrPuzzle);
        children.push_back(child);
        child->parent = this;
    }   
}

void Node::printPuzzle(){ //print puzzle
    int k = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout << puzzle[k++] << " ";
        cout << endl;
    }
    cout << endl;
}

bool Node::samePuzzle(int puzzleArr[9]){ //check if naa na bay nakapareha nga puzzle
    for(int i=0;i<9;i++)
        if(puzzle[i]!=puzzleArr[i])
            return false;
    return true;
}

void Node::moveAllDirections(){
    for(int i=0;i<9;i++)
        if(puzzle[i]==0)
            x = i; //gipangita kung unsa nga index ang blank tile
    
    moveLeft(puzzle, x);
    moveRight(puzzle, x);
    moveUp(puzzle, x);
    moveDown(puzzle, x);

}

UninformedSearch::UninformedSearch(){

}

list<Node*> UninformedSearch::breadthFirstSearch(Node *root){
    list<Node*> pathToSolution;
    list<Node*> openList;
    list<Node*> closedList;

    openList.push_back(root);
    bool goalFound = false;

    while(openList.size()>0&&!goalFound){
        Node* currentNode = openList.front();
        closedList.push_back(currentNode);
        openList.pop_front();

        currentNode->moveAllDirections();
        //currentNode->printPuzzle();
        for(list<Node*>::iterator it=currentNode->children.begin();it!=currentNode->children.end()&&!goalFound;++it){
            //Node* currentChild = currentNode->children.front();
            
            if((*it)->goalTest()){
                cout << "GOAL FOUND\n";
                goalFound = true;
                //trace dayun sa path kay nakit-an naman
                cout << "Tracing path...\n";
                Node *current = *it;
                pathToSolution.push_back(current);

                while(current->parent!=NULL){
                    current = current->parent;
                    pathToSolution.push_back(current);
                }
            }
            bool contains = false;
            for(list<Node*>::iterator itt=openList.begin();itt!=openList.end();++itt)
                if((*itt)->samePuzzle((*it)->puzzle))
                    contains = true;
            if(!contains)
                openList.push_back(*it);
        }
    }
    return pathToSolution;
}

// bool UninformedSearch::containsPuzzle(list<Node*> lest, Node *c){
    
// }
