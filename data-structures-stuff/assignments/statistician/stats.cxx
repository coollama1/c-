
//Name: Marvin Estime
//Date: Feb 24, 2018

    statistician::statistician()
    {//POSTCONDITION: Initialize object with length 0 and sum 0
        count = 0;
        total = 0;
    }
    void statistician::next(double r)
    {//POSTCODITION: The number r is "added" to the statistician. Values are adjusted
    //accordingly
        count++;
        total += r;
        if(count == 1)
        {
            tinyest = r;
            largest = r;
        }
        else if(r > largest)
        {
            largest = r;
        }
        else if(r < tinyest)
        {
            tinyest = r;
        }
    }

    void statistician::reset()
    {//POSTCONDITION: Sets the length and sum back to 0, as if the object were just
    //created
        count = 0;
        total = 0;
    }

    int statistician::length () const
    {//POSTCONDITION: Number of elements "recorded" in the statistiian is returned

        return count;
    }
    double statistician::sum () const
    {//POSTCONDITION: Sum of all of the elements whithin the statistician is returned

        return total;
    }
    double statistician::mean() const
    {//PRECONDITION: Length of statistician > 0
    //POSTCONDITION: Average of all of the elements is returned
        return total/count;
    }
    double statistician::minimum () const
    {//PRECONDITION: Length of statistician > 0
    //POSTCONDITION: Lowest value recorded in the statistician is returned
        return tinyest;
    }
    double statistician::maximum () const
    {//PRECONDITION: Length of statistician > 0
    //POSTCONDITION: Highest value recorded in the statistician is returned
        return largest;
    }
    statistician operator+(const statistician& s1, const statistician& s2) //friend function info
                                                            //at the bottom
    {//POSTCONDITION: Returns a statistician object that contains the elements from
    //both of the provided statistician objects (values are adjusted accordingly)

        statistician s3;
        s3.count = s1.count + s2.count;
        s3.total = s1.total + s2.total;
        
        if(s1.count == 0)
        {
            s3.largest = s2.largest;
            s3.tinyest = s2.tinyest;
            return s3;
        }
        else if (s2.count == 0)
        {
            s3.largest = s1.largest;
            s3.tinyest = s1.tinyest;
            return s3;
        }
        if(s1.tinyest < s2.tinyest)
        {
            s3.tinyest = s1.tinyest;
        }
        else
        {
            s3.tinyest = s2.tinyest;
        }
        if(s1.largest > s2.largest)
        {
            s3.largest = s1.largest;
        }
        else
        {
            s3.largest = s2.largest;
        }
        return s3;
    }

    statistician operator*(double scale, const statistician& s)
    {//POSTCONDITION: all numbers whithin the statisitician are multiplied by the
    //scale (values are adjusted accordingly)

        if(s.count == 0)
        {
            return s;
        }
        statistician output;
        output.count = s.count;
        output.total = scale * s.total;
        if(scale < 0)
        {
            output.tinyest = scale * s.largest;
            output.largest = scale * s.tinyest;
        }
        else
        {
            output.tinyest = scale * s.tinyest;
            output.largest = scale * s.largest;   
        }

        return output;
    }

    bool operator==(const statistician& s1, const statistician& s2)
    {//POSTCONITION: Returns true if the values of one statistican is equal to the
    //corresponding values of the other; returns false otherwise
    
        if(s1.length() == 0 && s2.length() == 0 )
        {
            return true;
        }
        if(s1.length() != s2.length())
        {
            return false;
        }
        if(s1.sum() != s2.sum())
        {
            return false;
        }
        if(s1.mean() != s2.mean())
        {
            return false;
        }
        if(s1.minimum() != s2.minimum())
        {
            return false;
        }
        if(s1.maximum() != s2.maximum())
        {
            return false;
        }
        return true;
    }
    //friend functions and classes have access to the private members of the class that
    //their prototype is stated in

    //friendship is not mutual,
    //for ex:
    /*
    class A
    {
    private:
        int a;
    public:
        friend void B::showA(A& obj);
    };

    class B
    {
    private:
        int b;
    public:
        void showA(A& obj);
    };

    void B::showA(A& obj) can access the private members of A, but A cannot access the
    private members of B
    */
    

