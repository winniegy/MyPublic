#Implement all parts of this assignment within (this) module2_assignment2.rb file

#Implement a class called LineAnalyzer.
class LineAnalyzer
  #Implement the following read-only attributes in the LineAnalyzer class. 
  #* highest_wf_count - a number with maximum number of occurrences for a single word (calculated)
  #* highest_wf_words - an array of words with the maximum number of occurrences (calculated)
  #* content          - the string analyzed (provided)
  #* line_number      - the line number analyzed (provided)
  attr_reader :highest_wf_count, :highest_wf_words, :content, :line_number

  #Add the following methods in the LineAnalyzer class.
  #* initialize() - taking a line of text (content) and a line number
  #* calculate_word_frequency() - calculates result

  #Implement the initialize() method to:
  #* take in a line of text and line number
  #* initialize the content and line_number attributes
  #* call the calculate_word_frequency() method.
  def initialize(content, line_number)
    @content = content
    @line_number = line_number
    @highest_wf_count = 0
    @highest_wf_words = []
    calculate_word_frequency() 
  end

  #Implement the calculate_word_frequency() method to:
  #* calculate the maximum number of times a single word appears within
  #  provided content and store that in the highest_wf_count attribute.
  #* identify the words that were used the maximum number of times and
  #  store that in the highest_wf_words attribute.
  def calculate_word_frequency()
    counts = Hash.new 0
    @content.split(" ").each do |word|
      counts[word.downcase] += 1
    end    
    counts = Hash[counts.sort_by{|key,value| -value}]
    @highest_wf_count = counts.values[0]
    counts.each do |key, value|
      # equal num of occurances, push in value
      if @highest_wf_count == value
        @highest_wf_words.push(key)
      # since descending sort, not possible to be larger, less should not push in
      end
    end
  end
end

#  Implement a class called Solution. 
class Solution

  # Implement the following read-only attributes in the Solution class.
  #* analyzers - an array of LineAnalyzer objects for each line in the file
  #* highest_count_across_lines - a number with the maximum value for highest_wf_words attribute in the analyzers array.
  #* highest_count_words_across_lines - a filtered array of LineAnalyzer objects with the highest_wf_words attribute 
  #  equal to the highest_count_across_lines determined previously.
  attr_reader :analyzers, :highest_count_across_lines, :highest_count_words_across_lines
  
  # Unfortunately has to be defined in order to make solution_spec.rb happy...
  # It checks analyzers length directly after Solution.new, before calling analyze_file()
  def initialize()
    @analyzers = []
  end
  
  # Implement the following methods in the Solution class.
  #* analyze_file() - processes 'test.txt' intro an array of LineAnalyzers and stores them in analyzers.
  #* calculate_line_with_highest_frequency() - determines the highest_count_across_lines and 
  #  highest_count_words_across_lines attribute values
  #* print_highest_word_frequency_across_lines() - prints the values of LineAnalyzer objects in 
  #  highest_count_words_across_lines in the specified format
  
  # Implement the analyze_file() method() to:
  #* Read the 'test.txt' file in lines 
  #* Create an array of LineAnalyzers for each line in the file
  def analyze_file()
    if File.exist? 'test.txt'
      line_num = 1;
      File.foreach( 'test.txt' ) do |line|
        @analyzers.push(LineAnalyzer.new(line.chomp, line_num))
        line_num += 1;
      end
    end
  end

  # Implement the calculate_line_with_highest_frequency() method to:
  #* calculate the maximum value for highest_wf_count contained by the LineAnalyzer objects in analyzers array
  #  and stores this result in the highest_count_across_lines attribute.
  #* identifies the LineAnalyzer objects in the analyzers array that have highest_wf_count equal to highest_count_across_lines 
  #  attribute value determined previously and stores them in highest_count_words_across_lines.
  def calculate_line_with_highest_frequency()
    @analyzers.sort!{|a,b| b.highest_wf_count <=> a.highest_wf_count}
    
    @highest_count_across_lines = @analyzers.first.highest_wf_count    
    @highest_count_words_across_lines = []
    @analyzers.each do |analyzer|
      if analyzer.highest_wf_count == @highest_count_across_lines
        @highest_count_words_across_lines.push(analyzer)
      end
    end
  end

  #Implement the print_highest_word_frequency_across_lines() method to
  #* print the values of objects in highest_count_words_across_lines in the specified format
  def print_highest_word_frequency_across_lines()
    puts "The following words have the highest word frequency per line:\n"
    @highest_count_words_across_lines.each do |analyzer|
      puts "#{analyzer.highest_wf_words} (appears in line #{analyzer.line_number})" 
    end
  end
end
