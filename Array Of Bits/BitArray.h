class BitArray {
private:
    int size;
    unsigned char* data;

public:
    BitArray();
    explicit BitArray(int size); //explicit prevents implicit conversions from int to BitArray
    BitArray(const BitArray& other); 
    BitArray(BitArray&& other) noexcept; //no throwing exceptions
    ~BitArray();

    bool getValue(int index) const;
    void setValue(int index, bool value);
    void printArray() const;
    BitArray merge(const BitArray& other) const;
    BitArray differ(const BitArray& other) const;

    bool operator[](int index) const;

};
