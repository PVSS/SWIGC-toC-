#ifndef _IKVP_SWIG_
#define _IKVP_SWIG_

typedef int IKVPValueType;

class  IKVPNode
{
public:
	// virtual ~IKVPNode() = 0;

	/// Gets the local name of the node.
	//virtual std::string GetName() const = 0;

	/// Gets the first child of the node. If there is no such node, NULL is returned.
	virtual IKVPNode* GetFirstChild() const = 0;

	/// Gets the node immediately following this node (in other words, the next immediate sibling).
	/// If there is no next node, NULL is returned.
	virtual IKVPNode* GetNextSibling() const = 0;

	
		/// Gets the value associated with this KVPNode. Returns value of type IKVPValueType
	virtual IKVPValueType GetValue() const = 0;

	/// Sets the value associated with this KVPNode
	//virtual void SetValue(const IKVPValueType& value) = 0;

};

class KVPNode : public IKVPNode
{
public:
	KVPNode(IKVPNode* parent, IKVPValueType _val) : Parent(parent), FirstChild(nullptr), NextSibling(nullptr),val(_val) {}
	KVPNode(const KVPNode& other) : Parent(other.Parent), FirstChild(other.FirstChild), NextSibling(other.NextSibling) {}
	KVPNode(KVPNode&& other) : Parent(other.Parent), FirstChild(other.FirstChild), NextSibling(other.NextSibling) {}
	~KVPNode() = default;

	virtual IKVPNode* GetParent() const { return Parent; }
	virtual IKVPNode* GetFirstChild() const { return FirstChild; }
	virtual IKVPNode* GetNextSibling() const { return NextSibling; }
	virtual IKVPValueType GetValue() const { return val; }

	void SetFirstChild(IKVPNode* child) { FirstChild = child; }
	void SetNextSibling(IKVPNode* sibling) { NextSibling = sibling; }

	void AddChild(IKVPNode* node)
	{
		if (FirstChild == nullptr)
		{
			FirstChild = node;
		}
		else
		{
			KVPNode* child = static_cast<KVPNode*>(FirstChild);
			while (child->GetNextSibling() != nullptr)
			{
				child = static_cast<KVPNode*>(child->GetNextSibling());
			}
			child->SetNextSibling(node);
		}
	}

private:
	IKVPValueType val;
	IKVPNode* Parent;
	IKVPNode* FirstChild;
	IKVPNode* NextSibling;
};

template<typename Derived>
class KVPAccessProvider : public IKVPNode
{
public:
	KVPAccessProvider() :RootNodePtr(nullptr)
	{

	}

	void Index(int data)
	{
		// Creating a Fibonacci Series to represent the Tree that is created after Visiting Scan protocol.
		RootNodePtr = new KVPNode(nullptr, data);
		IKVPNode* fc = new KVPNode(RootNodePtr, 1);
		RootNodePtr->AddChild(fc);

		{
			IKVPNode* sb = new KVPNode(RootNodePtr, 1);
			RootNodePtr->AddChild(sb);
		}
		{
			IKVPNode* sb = new KVPNode(RootNodePtr, 2);
			RootNodePtr->AddChild(sb);
		}
		{
			IKVPNode* sb = new KVPNode(RootNodePtr, 3);
			RootNodePtr->AddChild(sb);
		}
		{
			IKVPNode* sb = new KVPNode(RootNodePtr, 5);
			RootNodePtr->AddChild(sb);
		}
		{
			IKVPNode* sb = new KVPNode(RootNodePtr, 8);
			RootNodePtr->AddChild(sb);
		}

	}
	virtual IKVPNode* GetFirstChild() const { return RootNodePtr->GetFirstChild(); }
	virtual IKVPNode* GetNextSibling() const { return RootNodePtr->GetNextSibling(); }
	virtual IKVPValueType GetValue() const { return RootNodePtr->GetValue(); }

private:
	KVPNode* RootNodePtr;


};

#endif