#include <iostream>

using namespace std;

// Базовий клас
class Tree {
public:
    virtual void draw() const = 0; // Віртуальний метод draw
};

// Похідний клас 1
class Tree1 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 1:" << endl;
        cout << " /\\" << endl;
        cout << "//\\\\" << endl;
    }
};

// Похідний клас 2
class Tree2 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 2:" << endl;
        cout << " /\\" << endl;
        cout << "/**\\" << endl;
    }
};

// Похідний клас 3
class Tree3 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 3:" << endl;
        cout << " /\\" << endl;
        cout << "/++\\" << endl;
    }
};

int main() {
    // Масив вказівників на об'єкти базового класу
    Tree* trees[3];

    // Створюємо об'єкти різних дерев і присвоюємо їх масиву
    Tree1 tree1;
    Tree2 tree2;
    Tree3 tree3;

    trees[0] = &tree1;
    trees[1] = &tree2;
    trees[2] = &tree3;

    // Викликаємо метод draw для кожного дерева
    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
    }

    return 0;
}
