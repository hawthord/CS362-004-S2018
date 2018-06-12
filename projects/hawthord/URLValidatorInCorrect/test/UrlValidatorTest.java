

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing  
      String[] schemes = {"http","https"};
      UrlValidator urlValidator = new UrlValidator(schemes);
      if (urlValidator.isValid("www.a.com")) {
          System.out.println("url is valid");
      } else {
          System.out.println("url is invalid");
      }
      System.out.println(urlValidator.isValid("The Rain"));
   
   
   }
   
   
   public void testYourFirstPartition()
   {
     //You can use this function to implement your First Partition testing
      //done to only test parts of a URL, not an entire one
         String[] schemes = {"http","https"};
         UrlValidator urlValidator = new UrlValidator(schemes);
         String[] urlPass = {"https://", "https://www.", "https://www.google.", "https://www.com/" };
         for(String urls: urlPass)
         if (urlValidator.isValid(urls)) {
             System.out.println("url is valid");
             } else {
               System.out.println("url is invalid");
              }

   }

 public void testYourSecondPartition(){
         //You can use this function to implement your Second Partition testing     
          //done to only test parts of a URL, not an entire one
for(int p=0; p < 2; p++) {
    if (p==0) {
         String[] schemes = {"http","https"};
         UrlValidator urlValidator = new UrlValidator(schemes);
    }
else{
    UrlValidator urlValidator = new UrlValidator(null);
}
         String[] newSchemes = {"https://", "http", "https"};
         String[] newAuthority = {"www.google.com","goo.gle.com", "google.com"};
         String[] newPath = {"/search", "//test","",};
         String[] newQuery = {"?q=best+way+to+use+java", "?/help"};
         for(int i =0; i < newSchemes.length; i++) {
             for(int j =0; j < newAuthority.length; j++) {
                 for(int k =0; k < newPath.length; k++) {
                     for(int l =0; l < newQuery.length; l++) {
                         String Url2Check = new String(newSchemes[i]+newAuthority[j]+newPath[k]+newQuery[l]);
                         System.out.println(Url2Check);
                     if (urlValidator.isValid(Url2Check)) {
                        System.out.println("valid");
                         } else {
                         System.out.println("invalid");
                         } 
                     }
                 }     
             }
         }
}
   }


   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
