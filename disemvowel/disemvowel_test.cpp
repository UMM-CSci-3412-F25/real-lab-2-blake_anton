#include <gtest/gtest.h>

#include "disemvowel.h"


TEST(Disemvowel, HandleEmptyString) {
  const char* s = disemvowel((char*) "");	
  ASSERT_STREQ( "", s);
  free((void*) s);

}

TEST(Disemvowel, HandleNoVowels) {
  const char* s = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", s);
  free((void*) s);

}

TEST(Disemvowel, HandleOnlyVowels) {
  const char* s = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", s);
  free((void*) s);

}

TEST(Disemvowel, HandleMorrisMinnesota) {
  const char* s = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", s);
  free((void*) s);


}

TEST(Disemvowel, HandlePunctuation) {
  const char* s = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", s);
  free((void*) s);

}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  
  char const* dis = disemvowel(str);
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  ASSERT_STREQ("xyz", dis);
  free((void*) str);
  free((void*) dis);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
