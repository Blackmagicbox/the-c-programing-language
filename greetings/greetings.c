#include <stdio.h>
#include <time.h>


int moon_phase (int year, int month, int day) {

  // int d;
  int d = 0;
  int g, e;


  // // Convert month number to be 3..14 (March=3, April=4, etc.)
  if (month == 2) {
    d += 31;
  } else if (month > 3) {
    d += 59 + (month - 3)*30.6 +  0.5;
  }

  // Separate out centuries and years
  g = (year - 1900) % 19;
  e = (11*g + 29) % 30;

  // Account for leap year
  if ((e == 25 && g > 11) || e == 24) {
    e++;
  }

  // Find full moon's calendar date
  return ((((e + d) * 6+5) % 177) / 22 & 7);
}

char *get_moon_phase_name (int phase) {
  char *phase_name;
  switch (phase) {
    case 0:
      phase_name = "new moon";
      break;
    case 1:
      phase_name = "waxing crescent moon";
      break;
    case 2:
      phase_name = "first quarter moon";
      break;
    case 3:
      phase_name = "waxing gibbous moon";
      break;
    case 4:
      phase_name = "full moon";
      break;
    case 5:
      phase_name = "waning gibbous moon";
      break;
    case 6:
      phase_name = "last quarter moon";
      break;
    case 7:
      phase_name = "waning crescent moon";
      break;
    default:
      phase_name = "ERROR";
      break;
  }
  return phase_name;
}


int main (int argc, char *argv[]) {
  time_t now ;
  struct tm *clock;
  int hour;
  char time_string[65];
  time(&now);
  clock = localtime(&now);
  hour = clock -> tm_hour;

  int phase = moon_phase(clock -> tm_year + 1900, clock -> tm_mon + 1, clock -> tm_mday);
  char *phase_name = get_moon_phase_name(phase);

  strftime(time_string,64,"Today is %A, %B %d, %Y%nIt is %r%n",clock);

  if(hour < 5) {
    printf("Working late? ");
  }

  printf("Good ");
  if(hour < 12) {
    printf("morning, ");
  } else if (hour < 17) {
    printf("afternoon, ");
  } else {
    printf("evening, ");
  }

  if(argc > 1) {
    printf("%s!\n", argv[1]);
  } else {
    printf("code master!\n");
  }
  printf("%s", time_string);
  printf("Tonight we have a %s on the sky.\n", phase_name);

  return 0;
}