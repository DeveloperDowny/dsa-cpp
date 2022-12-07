import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter main memory size : ");
        int memory = sc.nextInt();
        System.out.print("Enter block size : ");
        int block = sc.nextInt();
        System.out.print("Enter cache size : ");
        int cache = sc.nextInt();
        double noOfBlocks = memory / block;
        int b = (int) noOfBlocks;
        System.out.println("Number of blocks : " + b);
        double noOfLines = cache / block;
        int n = (int) noOfLines;
        System.out.println("Number of lines : " + n);
        double d = 2;
        double blockIndex = (int) (Math.log(noOfBlocks) / Math.log(d));
        int a = (int) blockIndex;
        System.out.println("Block Index : " + a);
        double cacheIndex = (int) (Math.log(noOfLines) / Math.log(d));
        int c = (int) cacheIndex;
        System.out.println("Cache Index : " + c);
        int arr1[] = new int[b];
        int arr2[] = new int[2];
        for (int i = 0; i < a; i++) {
            arr1[i] = 0;
        }
        System.out.print("Enter the number : ");
        int num = sc.nextInt();
        int t = a - 1;
        while (num > 0) {
            int r = num % 2;
            num = num / 2;
            arr1[t] = r;
            t--;
        }
        arr2[1] = arr1[a - 1];
        arr2[0] = arr1[a - 2];
        for (int i = 0; i < a; i++) {
            System.out.print(arr1[i] + " ");
        }
        System.out.println("");
        int store = arr2[0] * 2 + arr2[1] * 1;
        System.out.println("Number will be stored at : " + arr2[0] + arr2[1]);
        System.out.println("Number will be stored at (Integer Value) : " + store);
    }
}