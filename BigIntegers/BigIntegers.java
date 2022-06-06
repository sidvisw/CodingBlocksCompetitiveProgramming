// Big Integer Class for Java | Powerful lot of Inbuilt functions
/*
Modular Arithmetic
GCD Calculation
Base Conversion
Power Calculation
Bitwise Operators
Prime Generation
and more...
*/
/*-------------------------CODE------------------------------*/
import java.math.BigInteger;
import java.util.Scanner;

public class BigIntegers {
    static void playWithBigInteger(){
        Scanner sc = new Scanner(System.in);
        String s1=sc.next();

        BigInteger b1=new BigInteger(s1);
        BigInteger b2=new BigInteger("12345678910111213");
        // b1=b1.add(b2);
        b1=b1.multiply(b2);
        System.out.println(b1);

        //Bit Count - Total Set Bits
        System.out.println(b1.bitCount());
        //Total no. of bits
        System.out.println(b1.bitLength());

        //Integer into BigInteger
        int a=sc.nextInt();
        int b=sc.nextInt();
        System.out.println(a+b);

        BigInteger b3=BigInteger.valueOf(a);
        BigInteger b4=BigInteger.valueOf(b);

        //GCD calculation
        System.out.println(b3.gcd(b4));

        //Base Conversion
        //Interpret the number in give base
        BigInteger b5=new BigInteger("1001",2);
        System.out.println(b5);

        //Power Calculation
        System.out.println(b3.pow(20));
    }
    public static void main(String[] args){
        playWithBigInteger();
    }
}