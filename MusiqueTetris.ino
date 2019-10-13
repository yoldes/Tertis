
const int buzzerPin = 9;

const int songLength = 58;

char notes[] = "eebcdcbAAcedcbbcdecAA dfagfecedcbbcdecAA ECDBCZJBECDBCEAAj"; // a space represents a rest

int beats[] = {4,4,2,2,4,2,2,4,2,2,4,2,2,4,2,2,4,4,4,4,4,4,6,2,4,2,2,6,2,4,2,2,4,2,2,4,4,4,4,4,4,8,8,8,8,8,8,8,8,8,8,8,8,4,4,4,4,16};

int tempo = 85;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  int i, duration;
  
  for (i = 0; i < songLength; i++)
  {
    duration = beats[i] * tempo;
    
    if (notes[i] == ' ') 
    {
      delay(duration);
    }
    else
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }
  
  while(true){}
}

int frequency(char note) 
{
  int i;
  const int numNotes = 17;
  
  char names[] = { 'J', 'Z', 'B', 'C', 'D', 'E', 'F', 'G', 'j', 'A', 'b', 'c', 'd', 'e', 'f', 'g', 'a' };
  int frequencies[] = { 208, 220, 247, 262, 294, 330, 349, 392, 415, 440, 494, 523, 587, 659, 698.5, 784, 880 };
  
  for (i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return(frequencies[i]);
    }
  }
  return(0);
}

