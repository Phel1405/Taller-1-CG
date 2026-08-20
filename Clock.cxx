// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------

#include "Clock.h"

#include <chrono>
#include <ctime>

// -------------------------------------------------------------------------
float get_hour() {
  auto now = std::chrono::system_clock::now();
  std::time_t current_time = std::chrono::system_clock::to_time_t(now);
  std::tm *local_time = std::localtime(&current_time);
  return (float(360 - (30 * (local_time->tm_hour % 12))));
}

// -------------------------------------------------------------------------
float get_minute() {
  auto now = std::chrono::system_clock::now();
  auto floor_days = std::chrono::floor<std::chrono::days>(now);
  std::chrono::hh_mm_ss time_of_day{now - floor_days};
  return (float(360 - (time_of_day.minutes().count() * 6)));
}

// -------------------------------------------------------------------------
float get_second() {
  auto now = std::chrono::system_clock::now();
  auto floor_days = std::chrono::floor<std::chrono::days>(now);
  std::chrono::hh_mm_ss time_of_day{now - floor_days};
  return (float(360 - (time_of_day.seconds().count() * 6)));
}

// eof - Clock.h
