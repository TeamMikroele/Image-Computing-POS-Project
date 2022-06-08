#pragma once
/**
 * This function enables multithread processing.
 * At first the number of iterations is counted, given the number of images to process.
 * Whole processing work is divided by the number of available threads to run.
 * Function starts each thread and as it finished its work, realeases a thread in a for() loop.
 */
void multithread();