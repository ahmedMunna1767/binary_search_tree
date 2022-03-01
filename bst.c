// #include "bst.h"

node *insertVal(node *rootNode, const int val)
{
    if (rootNode == 0)
    {
        node *newNode = malloc(sizeof(node));
        newNode->val = val;
        newNode->left = 0;
        newNode->right = 0;

        rootNode = newNode;
    }
    else
    {
        if (val < rootNode->val)
        {
            rootNode->left = insertVal(rootNode->left, val);
        }
        else
        {
            rootNode->right = insertVal(rootNode->right, val);
        }
    }

    return rootNode;
}

void printTreeInOrder(node *rootNode)
{
    if (rootNode == 0)
    {
        return;
    }
    printTreeInOrder(rootNode->left);
    printf("%d ", rootNode->val);
    printTreeInOrder(rootNode->right);
}

void printTreePreOrder(node *rootNode)
{
    if (rootNode == 0)
    {
        return;
    }
    printf("%d ", rootNode->val);
    printTreePreOrder(rootNode->left);
    printTreePreOrder(rootNode->right);
}

void printTreePostOrder(node *rootNode)
{
    if (rootNode == 0)
    {
        return;
    }
    printTreePostOrder(rootNode->left);
    printTreePostOrder(rootNode->right);
    printf("%d ", rootNode->val);
}

int getNodeCount(node *rootNode)
{
    if (rootNode == 0)
    {
        return 0;
    }

    return 1 + getNodeCount(rootNode->left) + getNodeCount(rootNode->right);
}

void deleteTree(node *rootNode)
{
    if (rootNode == 0)
    {
        return;
    }

    deleteTree(rootNode->left);
    deleteTree(rootNode->right);
    free(rootNode);
}

bool inTree(node *rootNode, const int val)
{
    if (rootNode == 0)
    {
        return false;
    }
    if (val < rootNode->val)
    {
        return inTree(rootNode->left, val);
    }
    else if (val > rootNode->val)
    {
        return inTree(rootNode->right, val);
    }
    else
    {
        return true;
    }
}

int getHeight(node *rootNode)
{
    if (rootNode == 0)
    {
        return 0;
    }

    return (getHeight(rootNode->left) > getHeight(rootNode->right)) ? (1 + getHeight(rootNode->left)) : (1 + getHeight(rootNode->right));
}

int getMin(node *rootNode)
{
    if (rootNode == 0)
    {
        return 0;
    }

    node *current = rootNode;

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->val;
}

int getMax(node *rootNode)
{
    if (rootNode == 0)
    {
        return 0;
    }

    node *current = rootNode;

    while (current->right != NULL)
    {
        current = current->right;
    }

    return current->val;
}

bool isBST(node *rootNode)
{
    if (rootNode == NULL)
        return true;

    return isBetween(rootNode, INT_MIN, INT_MAX);
}

bool isBetween(node *rootNode, int min, int max)
{
    if (rootNode == NULL)
        return true;

    // ensure subtrees are not hiding a value lower or higher than the subtree
    // allows
    return rootNode->val > min && rootNode->val < max &&
           isBetween(rootNode->left, min, rootNode->val) &&
           isBetween(rootNode->right, rootNode->val, max);
}

node *deleteVal(node *rootNode, const int val)
{
    if (rootNode == 0)
    {
        return rootNode;
    }

    if (val < rootNode->val)
    {
        rootNode->left = deleteVal(rootNode->left, val);
    }
    else if (val > rootNode->val)
    {
        rootNode->right = deleteVal(rootNode->right, val);
    }
    else
    {
        if (rootNode->left == 0 && rootNode->right == 0)
        {
            free(rootNode);
            rootNode = NULL;
        }
        else if (rootNode->left == 0)
        {
            node *temp = rootNode;
            rootNode = rootNode->right;
            free(temp);
        }
        else if (rootNode->right == NULL)
        {
            node *temp = rootNode;
            rootNode = rootNode->left;
            free(temp);
        }
        else
        {
            // 2 children - get min node of right subtree
            int rightMin = getMin(rootNode->right);
            rootNode->val = rightMin;
            rootNode->right = deleteVal(rootNode->right, rightMin);
        }
    }

    return rootNode;
}

int getSuccessor(node *rootNode, const int val)
{
    if (rootNode == NULL)
        return -1;

    node *target = rootNode;

    while (target->val != val)
    {
        if (val < target->val)
        {
            target = target->left;
        }
        else if (val > target->val)
        {
            target = target->right;
        }
    }

    if(target->left == 0 && target->right == 0){
        return -1;
    }
    // arrived at target node
    else if (target->right != NULL)
    {
        // get min value of right subtree
        return getMin(target->right);
    }
    else
    {
        // get lowest ancestor that is a left child in the path to target value
        node *successor = NULL;
        node *ancestor = rootNode;
        while (ancestor != NULL)
        {
            if (val < ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }

        return successor->val;
    }

}
